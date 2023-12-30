#include"mcal_external_interrupt.h"



static InterruptHandler INT0_InterruptHandler = NULL;
static InterruptHandler INT1_InterruptHandler = NULL;
static InterruptHandler INT2_InterruptHandler = NULL;

static InterruptHandler RB4_InterruptHandler_HIGH = NULL;
static InterruptHandler RB5_InterruptHandler_HIGH = NULL;
static InterruptHandler RB6_InterruptHandler_HIGH = NULL;
static InterruptHandler RB7_InterruptHandler_HIGH = NULL;

static InterruptHandler RB4_InterruptHandler_LOW = NULL;
static InterruptHandler RB5_InterruptHandler_LOW = NULL;
static InterruptHandler RB6_InterruptHandler_LOW = NULL;
static InterruptHandler RB7_InterruptHandler_LOW = NULL;


static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_opj);
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_opj);
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_opj);
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_opj);
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_opj);
static Std_ReturnType Interrupt_Clear_Flage(const interrupt_INTx_t *int_opj);

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_opj);


static Std_ReturnType Interrupt_RBx_Enable(const interrupt_RBx_t *int_opj);
static Std_ReturnType Interrupt_RBx_Disable(const interrupt_RBx_t *int_opj);
static Std_ReturnType Interrupt_RBx_Priority_Init(const interrupt_RBx_t *int_opj);
static Std_ReturnType Interrupt_RBx_Pin_Init(const interrupt_RBx_t *int_opj);

Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_opj){
Std_ReturnType ret = 0;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{
    
     ret =Interrupt_INTx_Disable(int_opj);
     ret |=Interrupt_Clear_Flage(int_opj);
     ret |=Interrupt_INTx_Edge_Init(int_opj);

/*#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
     ret = Interrupt_INTx_Priority_Init(int_opj);

#endif  */   
     ret |= Interrupt_INTx_Pin_Init(int_opj);
     ret |=Interrupt_INTx_SetInterruptHandler(int_opj);
     ret |=Interrupt_INTx_Enable(int_opj);
    
}
return ret;
}
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_opj){
Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{
    ret =Interrupt_INTx_Disable(int_opj);
}
return ret;
}
Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_opj){
Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{
    EXT_RBx_InterruptDisable();
    EXT_RBx_InterruptFlageClear();
    
    
    #ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
     

#endif 
    
    EXT_RBx_InterruptEnable();
    
}
return ret;
}
Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_opj){
Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{}
return ret;
}



static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_opj){
Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{
switch(int_opj->source){
        case INTERRUPT_EXTERNAL_INT0:
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
INTERRUPT_GlobalInterruptHighEnable();
#else            
INTERRUPT_GlobalInterruptEnable();
INTERRUPT_PeripheralInterruptEnable();
#endif
            EXT_INT0_InterruptEnable();
            ret = E_OK; 
            break;
        case INTERRUPT_EXTERNAL_INT1:
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
            if (INTERRUPT_LOW_PRIORITY==int_opj->prioprity){
            INTERRUPT_GlobalInterruptLowEnable();
            }else if (INTERRUPT_HIGH_PRIORITY==int_opj->prioprity){
            INTERRUPT_GlobalInterruptHighEnable();
            }
#else            
INTERRUPT_GlobalInterruptEnable();
INTERRUPT_PeripheralInterruptEnable();
#endif
            EXT_INT1_InterruptEnable();
            ret = E_OK;
            break;
        case INTERRUPT_EXTERNAL_INT2:
#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
            if (INTERRUPT_LOW_PRIORITY==int_opj->prioprity){
            INTERRUPT_GlobalInterruptLowEnable();
            }else if (INTERRUPT_HIGH_PRIORITY==int_opj->prioprity){
            INTERRUPT_GlobalInterruptHighEnable();
            }
#else            
INTERRUPT_GlobalInterruptEnable();
INTERRUPT_PeripheralInterruptEnable();
#endif
            EXT_INT2_InterruptEnable();
            ret = E_OK;
            break;
        default: ret = E_NOT_OK;
    }
}
return ret;
}
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_opj){
Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{
 switch(int_opj->source){
        case INTERRUPT_EXTERNAL_INT0:
            EXT_INT0_InterruptDisable();
            ret = E_OK; 
            break;
        case INTERRUPT_EXTERNAL_INT1:
            EXT_INT1_InterruptDisable();
            ret = E_OK;
            break;
        case INTERRUPT_EXTERNAL_INT2:
            EXT_INT2_InterruptDisable();
            ret = E_OK;
            break;
        default: ret = E_NOT_OK;
    }
}
return ret;
}

#ifdef INTERRUPT_PRIORITY_LEVELS_ENABLE
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_opj){
Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{
switch(int_opj->source){
        case INTERRUPT_EXTERNAL_INT1:
            if (INTERRUPT_LOW_PRIORITY==int_opj->prioprity){EXT_INT1_LowPrioritySet();}
            else if (INTERRUPT_HIGH_PRIORITY==int_opj->prioprity){EXT_INT1_HighPrioritySet();}
            ret = E_OK;
            break;
        case INTERRUPT_EXTERNAL_INT2:
            if (INTERRUPT_LOW_PRIORITY==int_opj->prioprity){EXT_INT2_LowPrioritySet();}
            else if (INTERRUPT_HIGH_PRIORITY==int_opj->prioprity){EXT_INT2_HighPrioritySet();}
            ret = E_OK;
            break;
        default: ret = E_NOT_OK;
    }
}
return ret;
}
#endif

static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_opj){
Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{

    switch(int_opj->source){
        case INTERRUPT_EXTERNAL_INT0:
             if (INTERRUPT_FALLING_EDGE==int_opj->edge){EXT_INT0_FallingEdgeSet();}
            else if (INTERRUPT_RISING_EDGE==int_opj->edge){EXT_INT0_RisingEdgeSet();}
            ret = E_OK; 
            break;
        case INTERRUPT_EXTERNAL_INT1:
            if (INTERRUPT_FALLING_EDGE==int_opj->edge){EXT_INT1_FallingEdgeSet();}
            else if (INTERRUPT_RISING_EDGE==int_opj->edge){EXT_INT1_RisingEdgeSet();}
            ret = E_OK;
            break;
        case INTERRUPT_EXTERNAL_INT2:
             if (INTERRUPT_FALLING_EDGE==int_opj->edge){EXT_INT2_FallingEdgeSet();}
            else if (INTERRUPT_RISING_EDGE==int_opj->edge){EXT_INT2_RisingEdgeSet();}
            ret = E_OK;
            break;
        default: ret = E_NOT_OK;
    }
}
return ret;
}
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_opj){
Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{
ret = gpio_pin_intialize_direction(&(int_opj->mcu_pin));
}
return ret;
}

static Std_ReturnType Interrupt_Clear_Flage(const interrupt_INTx_t *int_opj){
Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{
switch(int_opj->source){
    case INTERRUPT_EXTERNAL_INT0:
            EXT_INT0_InterruptFlageClear();
            ret = E_OK;
            break;    
    case INTERRUPT_EXTERNAL_INT1:
            EXT_INT1_InterruptFlageClear();
            ret = E_OK;
            break;
        case INTERRUPT_EXTERNAL_INT2:
            EXT_INT1_InterruptFlageClear();
            ret = E_OK;
            break;
        default: ret = E_NOT_OK;
    }
}
return ret;
}

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)){
Std_ReturnType ret = E_NOT_OK;
    if (InterruptHandler == NULL){
     ret = E_NOT_OK;
}else{
    INT0_InterruptHandler = InterruptHandler;
     ret = E_OK;
}
return ret;
}
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void)){
Std_ReturnType ret = E_NOT_OK;
    if (InterruptHandler == NULL){
     ret = E_NOT_OK;
}else{
    INT1_InterruptHandler = InterruptHandler;
     ret = E_OK;
}
return ret;
}
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void)){
Std_ReturnType ret = E_NOT_OK;
    if (InterruptHandler == NULL){
     ret = E_NOT_OK;
}else{
    INT2_InterruptHandler = InterruptHandler;
     ret = E_OK;
}
return ret;
}
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_opj){
    Std_ReturnType ret = E_NOT_OK;
if (int_opj == NULL){
     ret = E_NOT_OK;
}else{
switch(int_opj->source){
    case INTERRUPT_EXTERNAL_INT0:
           ret = INT0_SetInterruptHandler(int_opj->EXT_InterruptHandler);
            break;    
    case INTERRUPT_EXTERNAL_INT1:
            ret = INT1_SetInterruptHandler(int_opj->EXT_InterruptHandler);
            break;
        case INTERRUPT_EXTERNAL_INT2:
            ret = INT2_SetInterruptHandler(int_opj->EXT_InterruptHandler);
            break;
        default: ret = E_NOT_OK;
    }
}
return ret;}
