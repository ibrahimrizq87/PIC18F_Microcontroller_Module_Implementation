/* 
 * File:   ecu_button.h
 * Author: Ibrahim BEMO
 *
 * Created on November 3, 2023, 1:40 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

#include"../../MCAL_Layer/GPIO/hal_gpio.h"

typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED        
}button_stat_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW        
}button_connection_t;

typedef struct{
pin_config_t pin;
button_stat_t status;
button_connection_t connection;

}button_t;

Std_ReturnType button_intialize(const button_t *button);
Std_ReturnType button_read_status(const button_t *button,button_stat_t *stat);



#endif	/* ECU_BUTTON_H */

