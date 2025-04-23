#include "LF_gpio.h"

void GPIO_Init(void)
{
    RCC->APB2ENR = (1<<2);  //使能GPIOA时钟
    GPIOA->CRL |= (3<<0);   //PA0推挽输出50MHZ模式
    GPIOA->CRL |= (3<<4);   //PA1推挽输出50MHZ模式
    GPIOA->CRL |= (3<<8);   //PA2推挽输出50MHZ模式
    GPIOA->CRL |= (3<<12);  //PA3推挽输出50MHZ模式
    GPIOA->CRL |= (3<<16);  //PA4推挽输出50MHZ模式
    GPIOA->BSRR = 0xff;     //PA0~PA4输出高电平
}

void GPIO_Set(GPIOX gpiox, uint8_t pin)
{
    switch (gpiox)
    {
        case GPIO_A:    GPIOA->BSRR |= (1<<pin);    break;
        case GPIO_B:    GPIOB->BSRR |= (1<<pin);    break;
        case GPIO_C:    GPIOC->BSRR |= (1<<pin);    break;
        case GPIO_D:    GPIOD->BSRR |= (1<<pin);    break;
        case GPIO_E:    GPIOE->BSRR |= (1<<pin);    break;
        case GPIO_F:    GPIOF->BSRR |= (1<<pin);    break;
        case GPIO_G:    GPIOG->BSRR |= (1<<pin);    break;
        default:        break;
    }
}

void GPIO_Reset(GPIOX gpiox, uint8_t pin)
{
    switch (gpiox)
    {
        case GPIO_A:    GPIOA->BRR |= (1<<pin);    break;
        case GPIO_B:    GPIOB->BRR |= (1<<pin);    break;
        case GPIO_C:    GPIOC->BRR |= (1<<pin);    break;
        case GPIO_D:    GPIOD->BRR |= (1<<pin);    break;
        case GPIO_E:    GPIOE->BRR |= (1<<pin);    break;
        case GPIO_F:    GPIOF->BRR |= (1<<pin);    break;
        case GPIO_G:    GPIOG->BRR |= (1<<pin);    break;
        default:        break;
    }
}





