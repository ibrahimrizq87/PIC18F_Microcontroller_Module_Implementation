/* 
 * File:   mcal_internal_interrupt.h
 * Author: Ibrahim BEMO
 *
 * Created on November 10, 2023, 5:03 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* Section : Includes */
#include"mcal_interrupt_config.h"
/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */
#if ADC_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
#define ADC_InterruptEnable()     (PIE1bits.ADIE = 1)
#define ADC_InterruptDisable()     (PIE1bits.ADIE = 0)

#define ADC_InterruptFlageClear()     (PIR1bits.ADIF = 0)
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define ADC_HighPrioritySet()     (IPR1bits.ADIP = 1)
#define ADC_LowPrioritySet()     (IPR1bits.ADIP = 0)

#endif
#endif
/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */
#if TIMER0_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
#define TIMER0_InterruptEnable()     (INTCONbits.TMR0IE= 1)
#define TIMER0_InterruptDisable()     (INTCONbits.TMR0IE = 0)

#define TIMER0_InterruptFlageClear()     ( INTCONbits.TMR0IF= 0)
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define TIMER0_HighPrioritySet()     (INTCON2bits.TMR0IP = 1)
#define TIMER0_LowPrioritySet()     ( INTCON2bits.TMR0IP= 0)

#endif
#endif


#if TIMER1_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
#define TIMER1_InterruptEnable()     (PIE1bits.TMR1IE= 1)
#define TIMER1_InterruptDisable()     (PIE1bits.TMR1IE= 0)

#define TIMER1_InterruptFlageClear()     (PIR1bits.TMR1IF= 0)
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define TIMER1_HighPrioritySet()     (IPR1bits.TMR1IP = 1)
#define TIMER1_LowPrioritySet()     ( IPR1bits.TMR1IP= 0)

#endif
#endif


#if TIMER2_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
#define TIMER2_InterruptEnable()     (PIE1bits.TMR2IE= 1)
#define TIMER2_InterruptDisable()     (PIE1bits.TMR2IE= 0)

#define TIMER2_InterruptFlageClear()     (PIR1bits.TMR2IF= 0)
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define TIMER2_HighPrioritySet()     (IPR1bits.TMR2IP = 1)
#define TIMER2_LowPrioritySet()     ( IPR1bits.TMR2IP= 0)

#endif
#endif


#if TIMER3_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
#define TIMER3_InterruptEnable()     (PIE2bits.TMR3IE= 1)
#define TIMER3_InterruptDisable()     (PIE2bits.TMR3IE= 0)

#define TIMER3_InterruptFlageClear()     (PIR2bits.TMR3IF= 0)
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define TIMER3_HighPrioritySet()     (IPR2bits.TMR3IP = 1)
#define TIMER3_LowPrioritySet()     ( IPR2bits.TMR3IP= 0)

#endif
#endif



#if CCP1_INTERRUPT_ENABLE ==INTERRUPT_ENABLE
#define CCP1_InterruptEnable()     (PIE1bits.CCP1IE = 1)
#define CCP1_InterruptDisable()     (PIE1bits.CCP1IE = 0)

#define CCP1_InterruptFlageClear()     (PIR1bits.CCP1IF = 0)
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define CCP1_HighPrioritySet()     (IPR1bits.CCP1IP = 1)
#define CCP1_LowPrioritySet()     (IPR1bits.CCP1IP = 0)

#endif
#endif

/* Section: Data Type Declarations */

/* Section: Function Declarations */


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

