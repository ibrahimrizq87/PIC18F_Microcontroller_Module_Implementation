/* 
 * File:   ecu_led.h
 * Author: Ibrahim BEMO
 *
 * Created on November 1, 2023, 6:11 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

#include"../../MCAL_Layer/GPIO/hal_gpio.h"
#include"ecu_led_cfg.h"

typedef enum{
LED_ON =0,
LED_OFF
}led_status;

typedef struct{
    uint8 port :4;
    uint8 pin :3;
    uint8 status :1;
}led_t;

Std_ReturnType led_intialize(led_t *led);
Std_ReturnType led_turn_on(led_t *led);
Std_ReturnType led_turn_off(led_t *led);
Std_ReturnType led_turn_toggle(led_t *led);
#endif	/* ECU_LED_H */

