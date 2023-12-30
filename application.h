/* 
 * File:   application.h
 * Author: Ibrahim BEMO
 *
 * Created on November 1, 2023, 6:14 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include"ECU_Layer/ecu_layer_init.h"
#include"MCAL_Layer/ADC/hal_adc.h"
void application_intialize(void);

#define _XTAL_FREQ 4000000UL
#endif	/* APPLICATION_H */

