/* 
 * File:   mcal_external_interrupt.h
 * Author: Ibrahim BEMO
 *
 * Created on November 10, 2023, 5:03 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* Section : Includes */
#include"mcal_interrupt_config.h"
/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

#ifdef EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE

#define EXT_INT0_InterruptEnable()     (INTCONbits.INT0IE = 1)
#define EXT_INT0_InterruptDisable()     (INTCONbits.INT0IE = 0)

#define EXT_INT0_InterruptFlageClear()     (INTCONbits.INT0IF = 0)

#define EXT_INT0_RisingEdgeSet()     (INTCON2bits.INTEDG0 = 1)
#define EXT_INT0_FallingEdgeSet()     (INTCON2bits.INTEDG0 = 0)

// -----------------------------------------------------------//
#define EXT_INT1_InterruptEnable()     (INTCON3bits.INT1IE = 1)
#define EXT_INT1_InterruptDisable()     (INTCON3bits.INT1IE = 0)

#define EXT_INT1_InterruptFlageClear()     (INTCON3bits.INT1IF = 0)

#define EXT_INT1_RisingEdgeSet()     (INTCON2bits.INTEDG1 = 1)
#define EXT_INT1_FallingEdgeSet()     (INTCON2bits.INTEDG1 = 0)
// -----------------------------------------------------------//
#define EXT_INT2_InterruptEnable()     (INTCON3bits.INT2IE = 1)
#define EXT_INT2_InterruptDisable()     (INTCON3bits.INT2IE = 0)

#define EXT_INT2_InterruptFlageClear()     (INTCON3bits.INT2IF = 0)

#define EXT_INT2_RisingEdgeSet()     (INTCON2bits.INTEDG2 = 1)
#define EXT_INT2_FallingEdgeSet()     (INTCON2bits.INTEDG2 = 0)


#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define EXT_INT1_HighPrioritySet()     (INTCON3bits.INT1IP = 1)
#define EXT_INT1_LowPrioritySet()     (INTCON3bits.INT1IP = 0)

#define EXT_INT2_HighPrioritySet()     (INTCON3bits.INT2IP = 1)
#define EXT_INT2_LowPrioritySet()     (INTCON3bits.INT2IP = 0)
#endif
#endif

#ifdef EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE
#define EXT_RBx_InterruptEnable()     (INTCONbits.RBIE = 1)
#define EXT_RBx_InterruptDisable()     (INTCONbits.RBIE = 0)

#define EXT_RBx_InterruptFlageClear()     (INTCONbits.RBIF = 0)

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
#define EXT_RBx_HighPrioritySet()     (INTCON3bits.RBIP = 1)
#define EXT_RBx_LowPrioritySet()     (INTCON3bits.RBIP = 0)
#endif

#endif

/* Section: Data Type Declarations */

typedef void (*InterruptHandler)(void);
typedef enum{
    INTERRUPT_FALLING_EDGE=0,
    INTERRUPT_RISING_EDGE,
}interrupt_INTx_edge;

typedef enum{
    INTERRUPT_EXTERNAL_INT0 = 0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2
}interrupt_INTx_src;



typedef struct{
    void(* EXT_InterruptHandler) (void);
    pin_config_t mcu_pin;
    interrupt_INTx_edge edge;
    interrupt_INTx_src source;
    interrupt_priority_cfg prioprity;
    
}interrupt_INTx_t;

typedef struct{
    void(* EXT_InterruptHandler_HIGH) (void);
      void(* EXT_InterruptHandler_LOW) (void);
    pin_config_t mcu_pin;
    interrupt_priority_cfg prioprity;
}interrupt_RBx_t;

/* Section: Function Declarations */
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_opj);
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_opj);
Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_opj);
Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_opj);
#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

