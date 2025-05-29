#include "LF_header.h"

int main (void)
{
	GPIO_Init();

	while(1)
	{
		if(LED_TOGGLE)		LED_Toggle();
		else if(LED_FLOW)	LED_Flow();
		else if(Buzzer)		Buzzer_Toggle();
		else if(KEY_LED)	Key_LED();
		
	}
}
