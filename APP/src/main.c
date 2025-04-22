#include "stm32f10x.h"


int main (void)
{
	uint32_t delay = 9000000;
    GPIO_Init();
	while(1)
	{
		// while(delay--) {}
        // GPIOA->ODR &= ~(1<<0);
        // GPIOA->ODR &= ~(1<<1);
        // delay = 9000000;
		// while(delay--) {}
        // GPIOA->ODR |= (1<<0);
        // GPIOA->ODR |= (1<<1);
        // delay = 9000000;
	}
}

