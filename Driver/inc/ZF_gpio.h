#ifndef __ZF_GPIO_H__
#define __ZF_GPIO_H__

#include "stm32f10x.h"

typedef enum
{
    GPIO_A = 4,
    GPIO_B = 8,
    GPIO_C = 16,
    GPIO_D = 32,
    GPIO_E = 64
}RCC_GPIOx;

typedef enum
{
    INPUT = 0,
    OUTPUT_10MHZ,
    OUTPUT_20MHZ,
    OUTPUT_50MHZ
}GPIOx_Mode;

typedef enum
{
    INT_ANALOG = 0,
    INT_FLOAT,
    INT_PULL
}GPIOx_INCFG;

typedef enum
{
    OUT_PP = 0,
    OUT_OD,
    OUT_AFPP,
    OUT_AFOD
}GPIOx_OUTCFG;

typedef enum
{
    GPIOx0 = 0,
    GPIOx1,
    GPIOx2,
    GPIOx3,
    GPIOx4,
    GPIOx5,
    GPIOx6,
    GPIOx7,
    GPIOx8,
    GPIOx9,
    GPIOx10,
    GPIOx11,
    GPIOx12,
    GPIOx13,
    GPIOx14,
    GPIOx15,
}GPIOX_n;





void GPIO_Init(void);


#endif
