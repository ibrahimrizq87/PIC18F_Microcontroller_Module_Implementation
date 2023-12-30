/* 
 * File:   ecu_dc_motor.h
 * Author: Ibrahim BEMO
 *
 * Created on November 3, 2023, 8:05 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

#include"ecu_dc_motor_cfg.h"
#include"../../MCAL_Layer/GPIO/hal_gpio.h"


#define DC_MOTOR_ON_STAT  0x01U
#define DC_MOTOR_OFF_STAT 0x00U

typedef struct{
   uint8 motor_port :4;
   uint8 motor_pin :3;
   uint8 motor_status :1;
}dc_motor_pin_t;

typedef struct{
dc_motor_pin_t dc_motor[2];
}dc_motor_t;




Std_ReturnType dc_motor_intialize(const dc_motor_t *motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t *motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t *motor);
Std_ReturnType dc_motor_stop(const dc_motor_t *motor);


#endif	/* ECU_DC_MOTOR_H */

