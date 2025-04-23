#include "LF_gpio.h"

void GPIO_Init(void)
{
    RCC->APB2ENR = (1<<2);  //使能GPIOA时钟
    GPIOA->CRL |= (3<<0);   //PA0推挽输出50MHZ模式
    GPIOA->CRL |= (3<<4);   //PA1推挽输出50MHZ模式
    GPIOA->CRL |= (3<<8);   //PA2推挽输出50MHZ模式
    GPIOA->CRL |= (3<<12);  //PA3推挽输出50MHZ模式
    GPIOA->CRL |= (3<<16);  //PA4推挽输出50MHZ模式
    GPIOA->BRR = 0x1F;      //PA0~PA4输出低电平
}






