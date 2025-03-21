#include "FSM_line.h"

uint16_t threshold;

void update_threshold()
{
    uint16_t black, white;
    eeprom_read(EEPROM_BLACK, &black);
    eeprom_read(EEPROM_WHITE, &white);
    threshold = (black + white) / 2;    
}