/* 
 * File:   mcal_interrupt_config.h
 * Author: Ibrahim BEMO
 *
 * Created on November 10, 2023, 5:02 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* Section : Includes */
#include"../mcal_std_types.h"
#include"mcal_interrupt_gen_cfg.h"
#include"../GPIO/hal_gpio.h"
/* Section: Macro Declarations */
#define INTERRUPT_ENABLED 1
#define INTERRUPT_DISABLED 0

#define INTERRUPT_OCCUR 1
#define INTERRUPT_NOT_OCCUR 0

#define INTERRUPT_PRIORITY_ENABLE 1
#define INTERRUPT_PRIORITY_DISABLE 0



/* Section: Macro Functions Declarations */

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE

#define INTERRUPT_PriorityLevelEnable() (RCONbits.IPEN = 1)
#define INTERRUPT_PriorityLevelDisable() (RCONbits.IPEN = 0)

#define INTERRUPT_GlobalInterruptHighEnable() (INTCONbits.GIEH = 1)
#define INTERRUPT_GlobalInterruptHighDisable() (INTCONbits.GIEH = 0)

#define INTERRUPT_GlobalInterruptLowEnable() (INTCONbits.GIEL = 1)
#define INTERRUPT_GlobalInterruptLowDisable() (INTCONbits.GIEL = 0)

#else

#define INTERRUPT_GlobalInterruptEnable() (INTCONbits.GIE = 1)
#define INTERRUPT_GlobalInterruptDisable() (INTCONbits.GIE = 0)

#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0)
#endif

/* Section: Data Type Declarations */
typedef enum{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY,

}interrupt_priority_cfg;

/* Section: Function Declarations */


#endif	/* MCAL_INTERRUPT_CONFIG_H */

