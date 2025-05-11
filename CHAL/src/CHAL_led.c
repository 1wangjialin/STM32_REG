#include "CHAL_led.h"
#include "LF_gpio.h"

void CHAL_LedInit(void)
{
    GPIO_Init();
}

void CHAL_LedBlink(void)
{
    uint32_t delay = 9000000;
    while(delay--) {}
    GPIO_Set(GPIO_A,0);
    GPIO_Set(GPIO_A,1);
    GPIO_Set(GPIO_A,2);
    GPIO_Set(GPIO_A,3);
    GPIO_Set(GPIO_A,4);
    delay = 9000000;
    while(delay--) {}
    GPIO_Reset(GPIO_A,0);
    GPIO_Reset(GPIO_A,1);
    GPIO_Reset(GPIO_A,2);
    GPIO_Reset(GPIO_A,3);
    GPIO_Reset(GPIO_A,4);
    delay = 9000000;
}

void CHAL_Buzzer(void)
{
    uint32_t delay = 900000;
    while(delay--) {}
    GPIO_Set(GPIO_B,12);
    delay = 9000000;
    while(delay--) {}
    GPIO_Reset(GPIO_B,12);
}

uint16_t temp = 0;
void CHAL_LedFlow(void)
{
    uint32_t delay = 1500000;
    static uint16_t i = 0;

    while(delay--) {}

    GPIOA->ODR = ~(0x0001<<i);
    i++;
    if(i>2)
    {
        i = 0;
    }
    
}




