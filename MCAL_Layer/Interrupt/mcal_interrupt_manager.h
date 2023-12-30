/* 
 * File:   mcal_interrupt_manager.h
 * Author: Ibrahim BEMO
 *
 * Created on November 10, 2023, 5:04 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H


/* Section : Includes */
#include"mcal_interrupt_config.h"
/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */
void ADC_ISR(void);
void TIMER0_ISR(void);
void TIMER1_ISR(void);
void TIMER2_ISR(void);
void TIMER3_ISR(void);
#endif	/* MCAL_INTERRUPT_MANAGER_H */

