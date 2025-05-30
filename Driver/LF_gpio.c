#include "LF_header.h"

void GPIO_Init(void)
{
    RCC->APB2ENR |= (1<<2);
    RCC->APB2ENR |= (1<<3);
    GPIOA->CRL = 0;
    GPIOB->CRL = 0;
    GPIOB->CRH = 0;
    if(LED_TOGGLE)
    {  
        GPIOA->CRL |= (3<<0);
        GPIOA->BSRR = 1;
    }
    else if(LED_FLOW)
    {
        GPIOA->CRL = 0x33333333;
        GPIOA->BSRR = 0xFF;
    }
    else if(Buzzer)
    {
        GPIOB->CRH |= (3<<16);
        GPIOB->CRH &= ~(3<<18);
        GPIOB->BSRR = (1<<12);
    }
    else if(KEY_LED)
    {
        GPIOA->CRL |= (3<<4);
        GPIOA->CRL |= (3<<8);
        GPIOA->BSRR = 0x6;

        GPIOB->CRL |= (2<<6);
        GPIOB->CRH |= (2<<14);
    }
    
}

void LED_Toggle(void)
{
    Delay_ms(1000);
    GPIOA->BSRR = 0x10000;
    Delay_ms(1000);
    GPIOA->BSRR = 1;
}

uint16_t temp = 0xff;
uint16_t temp1 = 0xff;
void LED_Flow(void)
{
    uint8_t i = 0;
    
    for(i=0; i<8; i++)
    {
        Delay_ms(1000);
        temp = (0xFF & (~(0x1<<i)));
        temp1 = (0x1<<i);
        GPIOA->BSRR = temp1<<16;
        GPIOA->BSRR = temp;
    }
}

void Buzzer_Toggle(void)
{
    Delay_ms(1000);
    GPIOB->BSRR = 0x10000000;
    Delay_ms(1000);
    GPIOB->BSRR = 0x10001000;
}

void Key_LED(void)
{
    if(!(GPIOB->IDR & (1<<11)))
    {
        Delay_ms(10);
        GPIOA->BRR = (1<<2);
    }
    else
    {
        GPIOA->BSRR = (1<<2);
    }
    if(!(GPIOB->IDR & (1<<1)))
    {
        Delay_ms(10);
        GPIOA->BRR = (1<<1);
    }
    else
    {
        GPIOA->BSRR = (1<<1);
    }
}

