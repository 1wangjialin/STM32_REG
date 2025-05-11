#include "stm32f10x.h"
#include "CHAL.h"

int main (void)
{
    CHAL_LedInit();
	while(1)
	{
        CHAL_LedFlow();
		// CHAL_Buzzer();
	}
}

