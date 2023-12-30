/* 
 * File:   ecu_keypad.h
 * Author: Ibrahim BEMO
 *
 * Created on November 4, 2023, 8:26 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

#include"ecu_keypad_cfg.h"
#include"../../MCAL_Layer/GPIO/hal_gpio.h"

#define ECU_KEYPAD_ROWS 4
#define ECU_KEYPAD_COLUMNS 4


typedef struct{
    pin_config_t keypad_rows[ECU_KEYPAD_ROWS];
    pin_config_t keypad_columns[ECU_KEYPAD_COLUMNS];
}keypad_t;


Std_ReturnType keypad_intialize(const keypad_t *keypad);
Std_ReturnType keypad_get_value(const keypad_t *keypad,uint8 *value);
#endif	/* ECU_KEYPAD_H */

