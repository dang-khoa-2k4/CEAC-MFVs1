#ifndef EEPROM_H_
#define EEPROM_H_
#include "global.h"

typedef enum
{
    EEPROM_OK = 0,
    EEPROM_ERROR = 1
} EEPROM_STATUS;

#define EEPROM_BEGIN 0x08080000
#define EEPROM_SIZE 10

#define EEPROM_SERVO 0
#define EEPROM_BLACK 1
#define EEPROM_WHITE 2

void eeprom_init(uint32_t begin, uint16_t size);
uint32_t get_eeprom_size();
EEPROM_STATUS eeprom_read(uint16_t offset, uint32_t *pData);
EEPROM_STATUS eeprom_write(uint16_t offset, uint32_t *pData);

#endif /* EEPROM_H_ */