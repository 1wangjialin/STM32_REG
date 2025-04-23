#ifndef __LF_GPIO_H__
#define __LF_GPIO_H__

#include "stm32f10x.h"

typedef enum
{
    GPIO_A,
    GPIO_B,
    GPIO_C,
    GPIO_D,
    GPIO_E,
    GPIO_F,
    GPIO_G
}GPIOX;


void GPIO_Init(void);
void GPIO_Set(GPIOX gpiox, uint8_t pin);
void GPIO_Reset(GPIOX gpiox, uint8_t pin);


#endif
