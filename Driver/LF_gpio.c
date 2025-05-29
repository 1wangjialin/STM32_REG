#include "LF_header.h"

void GPIO_Init(void)
{
    if(LED_TOGGLE)
    {
        RCC->APB2ENR |= (1<<2);
        GPIOA->CRL |= ((3<<0) | (2<<2));
        GPIOA->BSRR = 1;
    }
    else if(LED_FLOW)
    {
        RCC->APB2ENR |= (1<<2);
        GPIOA->CRL = 0x88888888;
        GPIOA->BSRR = 0xFFFF;
    }
    else if(Buzzer)
    {
        RCC->APB2ENR |= (1<<3);
        GPIOB->CRH |= (3<<16);
        GPIOB->CRH &= ~(3<<18);
        GPIOB->BSRR = 0x10001000;
    }
    
}

void LED_Toggle(void)
{
    Delay_ms(1000);
    GPIOA->BSRR = 0x10000;
    Delay_ms(1000);
    GPIOA->BSRR = 1;
}

void LED_Flow(void)
{
    uint8_t i = 0;
    for(i=0; i<8; i++)
    {
        Delay_ms(100);
        GPIOA->BSRR = (0xFFFF & (~(0x1<<i)));
    }
}

void Buzzer_Toggle(void)
{
    Delay_ms(1000);
    GPIOA->BSRR = 0x10000000;
    Delay_ms(1000);
    GPIOA->BSRR = 0x10001000;
}

