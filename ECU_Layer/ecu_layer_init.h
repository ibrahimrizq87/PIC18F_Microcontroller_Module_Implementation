/* 
 * File:   ecu_layer_init.h
 * Author: Ibrahim BEMO
 *
 * Created on November 4, 2023, 8:20 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

#include"LED/ecu_led.h"
#include"Button/ecu_button.h"
#include"Relay/ecu_relay.h"
#include"DC_Motor/ecu_dc_motor.h"
#include"Seven_Segment/ecu_seven_segment.h"
#include"Keypad/ecu_keypad.h"

extern keypad_t keypad;

void ecu_layer_intialize(void);

#endif	/* ECU_LAYER_INIT_H */

