/* 
 * File:   ecu_seven_segment.h
 * Author: Ibrahim BEMO
 *
 * Created on November 4, 2023, 1:22 PM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

#include"ecu_seven_segment_cfg.h"
#include"../../MCAL_Layer/GPIO/hal_gpio.h"

#define SEVENSEGMENT_PIN0 0
#define SEVENSEGMENT_PIN1 1
#define SEVENSEGMENT_PIN2 2
#define SEVENSEGMENT_PIN3 3


typedef enum {
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE        
}segment_type_t;

typedef struct{
pin_config_t segment_pins[4];
segment_type_t segment_type ;
}segment_t;

Std_ReturnType seven_segment_intialize(segment_t *segment);
Std_ReturnType seven_segment_write_number(segment_t *segment,uint8 number);


#endif	/* ECU_SEVEN_SEGMENT_H */

