/* 
 * File:   ecu_relay.h
 * Author: Ibrahim BEMO
 *
 * Created on November 3, 2023, 9:10 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

#include"ecu_relay_cfg.h"
#include"../../MCAL_Layer/GPIO/hal_gpio.h"


#define RELAY_ON_STAT  0x01U
#define RELAY_OFF_STAT 0x00U

typedef struct{
   uint8 port :4;
   uint8 pin :3;
   uint8 status :1;
   
}relay_t;

Std_ReturnType relay_intialize(const relay_t *relay);
Std_ReturnType relay_turn_on(const relay_t *relay);
Std_ReturnType relay_turn_off(const relay_t *relay);
#endif	/* ECU_RELAY_H */

