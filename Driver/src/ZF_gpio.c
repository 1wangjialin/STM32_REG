#include "ZF_gpio.h"

void GPIO_Init(void)
{
    RCC->APB2ENR   = (1<<2);

    GPIOA->CRL    |= (3<<0);
	// GPIOA->CRL    |= (1<<2);
    GPIOA->CRL |= (3<<4);
	// GPIOA->CRL |= (1<<6);
    // GPIOA->BSRR   &= ~(3<<0);
    // GPIOA->BSRR   &= ~(1<<1);
    GPIOA->BSRR   |= (1<<1);
}

// void GPIO_Init(RCC_GPIOx gpiox, GPIOX_n gpiox_n, GPIOx_Mode Mode, )
// {
//     RCC->APB2ENR = gpiox;
//     switch (gpiox)
//     {
//         case GPIO_A:
//         {
//             GPIOA->CRL |= (Mode<<(gpiox_n*4));
//             break;
//         }
    
//         default:
//             break;
//     }

// }

// void GPIO_Set(RCC_GPIOx gpiox, GPIOX_n gpiox_n, GPIOx_Mode Mode)
// {
//     switch (gpiox)
//     {
//         case GPIO_A:
//         {
//             GPIOA->BSRR |= (Mode<<(gpiox_n*4));
//             break;
//         }
    
//         default:
//             break;
//     }
// }






