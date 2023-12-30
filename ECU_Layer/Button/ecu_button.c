#include"ecu_button.h"



Std_ReturnType button_intialize(const button_t *button){
Std_ReturnType ret = E_OK;
if (button == NULL){
    ret =E_NOT_OK;
}else{
    ret = gpio_pin_intialize_direction(&(button->pin));
}
return ret;
}

Std_ReturnType button_read_status(const button_t *button,button_stat_t *stat){
Std_ReturnType ret = E_OK;
logic_t logic = GPIO_LOW;
if (button == NULL){
    ret =E_NOT_OK;
}else{
   ret = gpio_pin_read_logic(&(button->pin), &logic);
    if (BUTTON_ACTIVE_HIGH == button->connection){
    if (logic == GPIO_HIGH){
        *stat=BUTTON_PRESSED;
    }else {
        *stat=BUTTON_RELEASED;
    }
    
    }else  if (BUTTON_ACTIVE_LOW == button->connection){
    if (logic == GPIO_LOW){
        *stat=BUTTON_PRESSED;
    }else {
        *stat=BUTTON_RELEASED;
    }
    }else{ /* nothing */ }
    
}
return ret;

}

