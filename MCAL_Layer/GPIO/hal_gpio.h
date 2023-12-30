/* 
 * File:   hal_gpio.h
 * Author: Ibrahim BEMO
 *
 * Created on November 1, 2023, 4:23 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section : Includes */



//#include"../pic18f4620.h" /* this one is in the video but I can not find the file in my compiler folder */
#include"../mcal_std_types.h"
#include"../device_config.h"
#include"hal_gpio_cfg.h"


/* Section: Data Type Declarations */

/*
typedef struct{
    port_index_t port;
    pin_index_t pin;
    direction_t direction;
    logic_t logic;
}pin_config_t;
 */
/* here we did not use the above way to save memory */

typedef struct{
    uint8 port       :3;
    uint8 pin        :3;
    uint8 direction  :1;
    uint8 logic      :1;
}pin_config_t;

typedef enum{
     GPIO_PIN0 = 0,
     GPIO_PIN1,
     GPIO_PIN2,
     GPIO_PIN3,
     GPIO_PIN4,
     GPIO_PIN5,
     GPIO_PIN6,
     GPIO_PIN7,
}pin_index_t;

typedef enum{
    PORTA_INDEX =0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef enum{
    GPIO_LOW=0,
    GPIO_HIGH
}logic_t;

typedef enum{
    GPIO_DIRECTION_OUTPUT=0,
    GPIO_DIRECTION_INPUT
}direction_t;
/* Section: Macro Declarations */
#define PORT_PIN_CONFIGRATION CONFIG_ENABLE
#define PORT_CONFIGRATION     CONFIG_ENABLE


#define BIT_MASK (uint8)1
#define PORT_MAX_NUMBER 5
#define PORT_PIN_MAX_NUMBER 8
/* Section: Macro Functions Declarations */
#define HWREG8(_x)                 (*((uint8 *)(_x)))
#define READ_BIT(REG, BIT_POSN)    ((REG >> BIT_POSN) & BIT_MASK)
#define SET_BIT(REG,BIT_POS)       (REG |= (BIT_MASK<<BIT_POS) )
#define CLEAR_BIT(REG,BIT_POS)     (REG &= ~(BIT_MASK<<BIT_POS) )
#define TOGGLE_BIT(REG,BIT_POS)    (REG ^= (BIT_MASK<<BIT_POS) )

/*Section: function declaration */

Std_ReturnType gpio_pin_intialize_direction(const pin_config_t *pin);
Std_ReturnType gpio_pin_get_status_direction(const pin_config_t *pin,direction_t *direction);
Std_ReturnType gpio_pin_intialize(const pin_config_t *pin);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin, logic_t *logic);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin, logic_t logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin);

Std_ReturnType gpio_port_intialize_direction(const port_index_t port,uint8 direction);
Std_ReturnType gpio_port_get_direction_status(const port_index_t port,uint8 *direction);
Std_ReturnType gpio_port_read_logic(const port_index_t port,uint8 *logic);
Std_ReturnType gpio_port_write_logic(const port_index_t port,uint8 logic);
Std_ReturnType gpio_port_toggle(const port_index_t port);








#endif	/* HAL_GPIO_H */

