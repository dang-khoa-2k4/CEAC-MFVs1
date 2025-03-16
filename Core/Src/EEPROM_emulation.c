#include "EEPROM_emulation.h"

static uint16_t e_size;
static uint32_t start_address, end_address;

static void flash_unlock(void)
{
    /*Check if the Lock is active*/
    if (FLASH->CR & FLASH_CR_LOCK)
    {
        FLASH->KEYR = 0x45670123U;
        FLASH->KEYR = 0xCDEF89ABU;
    }
}

static void flash_lock(void)
{
    FLASH->CR |= FLASH_CR_LOCK;
}

static void flash_read32(uint32_t addrs, uint32_t *rd32, uint32_t len)
{
    // Read data can be accessed straight away
    uint32_t tempAddrs = addrs;

    for (uint32_t i = 0; i < len; i++)
    {
        rd32[i] = *(__IO uint32_t *)tempAddrs;
        tempAddrs += 4;
    }
}

static void flash_write32(uint32_t addrs, uint32_t *wr32, uint32_t len)
{
    // Write data in 16-bit at a time
    uint32_t tempAddrs = addrs;

    /*Set the parallelism to 32-bit (x32)*/
    FLASH->CR |= FLASH_CR_PSIZE_1;

    for (uint32_t i = 0; i < len; i++)
    {
        // Set PG bit
        FLASH->CR |= FLASH_CR_PG;
        *(__IO uint32_t *)tempAddrs = wr32[i];
        tempAddrs += 4;

        // Wait for BSY flag to be idle
        while (((FLASH->SR) & (FLASH_SR_BSY)))
            ;
    }
    // Wait for BSY flag to be idle
    while (((FLASH->SR) & (FLASH_SR_BSY)))
        ;
    // Disable PG bit
    FLASH->CR &= ~FLASH_CR_PG;
}

void eeprom_init(uint32_t begin, uint16_t size)
{
    // 4 bytes per an instance
    end_address = begin + (uint32_t)(size << 2);
    start_address = begin;
    e_size = size;
}

uint32_t get_eeprom_size()
{
    return (uint32_t)e_size;
}

EEPROM_STATUS eeprom_read(uint16_t offset, uint32_t *pData)
{
    if (offset < 0 && offset >= e_size)
    {
        return EEPROM_ERROR;
    }
    // 4 bytes per an instance
    uint32_t addr = start_address + (uint32_t)(offset << 2);
    flash_read32(addr, pData, 1);
    return EEPROM_OK;
}

EEPROM_STATUS eeprom_write(uint16_t offset, uint32_t *pData)
{
    if (offset < 0 && offset >= e_size)
    {
        return EEPROM_ERROR;
    }
    // 4 bytes per an instance
    uint32_t addr = start_address + (uint32_t)(offset << 2);
    uint32_t temp;

    flash_unlock();
    flash_write32(addr, pData, 1);
    flash_lock();
    return EEPROM_OK;
}
