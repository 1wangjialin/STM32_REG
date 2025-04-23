#include "stm32f10x.h"
#include "CHAL.h"

int main (void)
{
    CHAL_LedInit();
	while(1)
	{
		// CHAL_LedBlink();
        CHAL_LedFlow();
        // GPIOA->BSRR = 0xff;
        // GPIOA->BRR  = 0xff;
	}
}

