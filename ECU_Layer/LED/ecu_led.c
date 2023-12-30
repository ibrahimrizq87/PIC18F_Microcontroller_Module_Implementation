/* 
 * File:   ecu_led.c
 * Author: Ibrahim BEMO
 *
 * Created on November 1, 2023, 6:11 PM
 */
#include"ecu_led.h"
#include"../../MCAL_Layer/GPIO/hal_gpio.h"



Std_ReturnType led_intialize(led_t *led){
Std_ReturnType ret =E_OK;    

    if ((led==NULL)||(led->pin > PORT_PIN_MAX_NUMBER-1)){
    ret =E_NOT_OK;
    }else{
pin_config_t pin={
.direction= GPIO_DIRECTION_OUTPUT,
.port =led->port,
.pin = led->pin,
.logic = led->status
};
        gpio_pin_intialize(&pin);
    }
return ret;
}
Std_ReturnType led_turn_on(led_t *led){
Std_ReturnType ret =E_OK;    
    if ((led==NULL)||(led->pin > PORT_PIN_MAX_NUMBER-1)){
    ret =E_NOT_OK;
    }else{
pin_config_t pin={
.direction= GPIO_DIRECTION_OUTPUT,
.port =led->port,
.pin = led->pin,
.logic = led->status
};
        gpio_pin_write_logic(&pin,GPIO_HIGH);
    }
return ret;

}
Std_ReturnType led_turn_off(led_t *led){
Std_ReturnType ret =E_OK;    
    if ((led==NULL)||(led->pin > PORT_PIN_MAX_NUMBER-1)){
    ret =E_NOT_OK;
    }else{
pin_config_t pin={
.direction= GPIO_DIRECTION_OUTPUT,
.port =led->port,
.pin = led->pin,
.logic = led->status
};
        gpio_pin_write_logic(&pin,GPIO_LOW);
    }
return ret;

}
Std_ReturnType led_turn_toggle(led_t *led){
Std_ReturnType ret =E_OK;    
    if ((led==NULL)||(led->pin > PORT_PIN_MAX_NUMBER-1)){
    ret =E_NOT_OK;
    }else{
pin_config_t pin={
.direction= GPIO_DIRECTION_OUTPUT,
.port =led->port,
.pin = led->pin,
.logic = led->status
};
        gpio_pin_toggle_logic(&pin);
    }
return ret;

}