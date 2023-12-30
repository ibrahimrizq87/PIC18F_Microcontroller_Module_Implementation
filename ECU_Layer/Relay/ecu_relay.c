#include"ecu_relay.h"


Std_ReturnType relay_intialize(const relay_t *relay){
Std_ReturnType ret=E_OK;
if (relay == NULL){
    ret = E_NOT_OK;
}else{
    pin_config_t pin={
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic = relay->status,
        .pin = relay->pin,
        .port = relay->port 
    };
    ret = gpio_pin_intialize(&pin);
}
return ret;
}

Std_ReturnType relay_turn_on(const relay_t *relay){
Std_ReturnType ret=E_OK;
if (relay == NULL){
    ret = E_NOT_OK;
}else{
    pin_config_t pin={
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic = relay->status,
        .pin = relay->pin,
        .port = relay->port 
    };
    ret = gpio_pin_write_logic(&pin,GPIO_HIGH);
}
return ret;
}

Std_ReturnType relay_turn_off(const relay_t *relay){
Std_ReturnType ret=E_OK;
if (relay == NULL){
    ret = E_NOT_OK;
}else{
    pin_config_t pin={
        .direction = GPIO_DIRECTION_OUTPUT,
        .logic = relay->status,
        .pin = relay->pin,
        .port = relay->port 
    };
    ret = gpio_pin_write_logic(&pin,GPIO_LOW);
}
return ret;
}
