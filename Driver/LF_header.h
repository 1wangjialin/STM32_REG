#ifndef __LF_HEADER_H__
#define __LF_HEADER_H__

#include "stm32f10x.h"
#include "LF_delay.h"
#include "LF_gpio.h"

void Delay_us(uint32_t us);
void Delay_ms(uint32_t ms);
void Delay_s(uint32_t s);

#endif
