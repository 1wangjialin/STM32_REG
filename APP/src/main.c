#include "stm32f10x.h"


int main (void)
{
	uint32_t delay = 9000000;
	// 使能GPIOA时钟
    RCC->APB2ENR |= (1<<2);
    // 设置GPIOA0 开漏输出 50MHZ
	GPIOA->CRL |= (3<<0);
	GPIOA->CRL |= (1<<2);
    // 设置GPIOA1 开漏输出 50MHZ
	GPIOA->CRL |= (3<<4);
	GPIOA->CRL |= (1<<6);
    // 设置GPIOA0，A1 开漏输出低电平
    GPIOA->ODR |= (0<<0);
    GPIOA->ODR |= (0<<1);
	while(1)
	{
		while(delay--) {}
        GPIOA->ODR &= ~(1<<0);
        GPIOA->ODR &= ~(1<<1);
        delay = 9000000;
		while(delay--) {}
        GPIOA->ODR |= (1<<0);
        GPIOA->ODR |= (1<<1);
        delay = 9000000;
	}
}

