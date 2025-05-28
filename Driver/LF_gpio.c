#include "LF_header.h"

void GPIO_Init(void)
{
    RCC->APB2ENR |= (1<<2);
    GPIOA->CRL |= ((3<<0) | (2<<2));
    GPIOA->BSRR |= (1<<0);
}

void LED_Toggle(void)
{
    Delay_ms(1000);
    GPIOA->BSRR &= (~(1<<0));
}


