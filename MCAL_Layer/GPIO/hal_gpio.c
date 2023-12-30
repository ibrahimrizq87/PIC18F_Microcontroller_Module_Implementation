/* 
 * File:   hal_gpio.c
 * Author: Ibrahim BEMO
 *
 * Created on November 1, 2023, 6:11 PM
 */

#include"hal_gpio.h"

/* reference to direction*/
volatile uint8 *tris_registers[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8 *port_registers[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
/* reference to latch "read or write"*/
volatile uint8 *lat_registers[]={&LATA,&LATB,&LATC,&LATD,&LATE};

#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_intialize_direction(const pin_config_t *pin){
Std_ReturnType ret= E_OK;
if ((pin == NULL) || (pin->pin > PORT_PIN_MAX_NUMBER -1)){
ret= E_NOT_OK;
}else{
    switch(pin->direction){
        case GPIO_DIRECTION_OUTPUT :
            CLEAR_BIT(*tris_registers[pin->port],pin->pin);
        break;
        case GPIO_DIRECTION_INPUT :
            SET_BIT(*tris_registers[pin->port],pin->pin);
            break;
        default: ret =  E_NOT_OK;
    }
    
}
return ret;
}
#endif

#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_get_status_direction(const pin_config_t *pin,direction_t *direction){
Std_ReturnType ret= E_OK;
if ((pin == NULL) ||(direction ==NULL)){
ret= E_NOT_OK;
}else{
    *direction = READ_BIT(*tris_registers[pin->port],pin->pin);
}
return ret;
}
#endif

#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_intialize(const pin_config_t *pin){
Std_ReturnType ret= E_OK;
if ((pin == NULL)||(pin->pin > PORT_PIN_MAX_NUMBER -1)){
ret= E_NOT_OK;
}else{
    ret = gpio_pin_intialize_direction(pin);
    ret = gpio_pin_write_logic(pin,pin->logic);
    
}

return ret;
}
#endif

#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin, logic_t *logic){
Std_ReturnType ret= E_OK;
if ((pin == NULL)||(pin->pin > PORT_PIN_MAX_NUMBER -1)){
ret= E_NOT_OK;
}else{
     *logic = READ_BIT(*port_registers[pin->port],pin->pin);
}

return ret;
}
#endif

#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin, logic_t logic){
Std_ReturnType ret= E_OK;
if ((pin == NULL)||(pin->pin > PORT_PIN_MAX_NUMBER -1)){
ret= E_NOT_OK;
}else{
     switch(logic){
        case GPIO_LOW :
            CLEAR_BIT(*lat_registers[pin->port],pin->pin);
        break;
        case GPIO_HIGH :
            SET_BIT(*lat_registers[pin->port],pin->pin);
            break;
        default: ret =  E_NOT_OK;
    }
}

return ret;
}
#endif

#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin){
Std_ReturnType ret= E_OK;
if ((pin == NULL)||(pin->pin > PORT_PIN_MAX_NUMBER -1)){
ret= E_NOT_OK;
}else{
    TOGGLE_BIT(*lat_registers[pin->port],pin->pin);
}

return ret;
}
#endif
// ------------ port functions --------------------//

#if PORT_CONFIGRATION == CONFIG_ENABLE

Std_ReturnType gpio_port_intialize_direction(const port_index_t port,uint8 direction){
Std_ReturnType ret= E_OK;
if (port > PORT_MAX_NUMBER-1){
    ret=E_NOT_OK;
}else{
*tris_registers[port] =direction;
}
return ret;
}
Std_ReturnType gpio_port_get_direction_status(const port_index_t port,uint8 *direction){
Std_ReturnType ret= E_OK;
if ((port > PORT_MAX_NUMBER-1) || (direction ==NULL)){
    ret=E_NOT_OK;
}else{
    *direction = *tris_registers[port];
}
return ret;
}
Std_ReturnType gpio_port_read_logic(const port_index_t port,uint8 *logic){
Std_ReturnType ret= E_OK;
if ((port > PORT_MAX_NUMBER-1)||(logic==NULL)){
    ret=E_NOT_OK;
}else{
    *logic = *lat_registers[port];
}
return ret;
}
Std_ReturnType gpio_port_write_logic(const port_index_t port,uint8 logic){
Std_ReturnType ret= E_OK;
if (port > PORT_MAX_NUMBER-1){
    ret=E_NOT_OK;
}else{
    *lat_registers[port]=logic;
}
return ret;
}
Std_ReturnType gpio_port_toggle(const port_index_t port){
Std_ReturnType ret= E_OK;
if (port > PORT_MAX_NUMBER-1){
    ret=E_NOT_OK;
}else{
   *lat_registers[port] = *lat_registers[port] ^ 0xFF; 
}
return ret;
}
#endif



