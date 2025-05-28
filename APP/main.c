#include "LF_header.h"

int main (void)
{
	GPIO_Init();

	while(1)
	{
		LED_Toggle();
	}
}
