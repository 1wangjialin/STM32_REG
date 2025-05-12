#include "CHAL_timer.h"

void Timer2_Init(void)
{
    RCC->APB1ENR |= (1<<0);     //使能TIM2时钟
    TIM2->SMCR &= ~(0x7);       //关闭从模式，选择由内部时钟驱动
    TIM2->CR1 &= ~(3<<8);       //时钟不分频
    TIM2->CR1 &= ~(1<<4);       //向上计数
    TIM2->PSC = 7200-1;         //7200分频，分频后为10KHZ 100us
    TIM2->ARR = 10000-1;        //1S定时
    TIM2->CR1 |= (1<<7);        //ARR影子寄存器使能
    TIM2->SR &= ~(1<<0);        //清除中断标志位
    TIM2->DIER |= (1<<0);       //允许更新中断

    /*NVIC中断分组*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//配置NVIC为分组2
	/*NVIC配置*/
	NVIC_InitTypeDef NVIC_InitStructure;						//定义结构体变量
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;				//选择配置NVIC的TIM2线
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//指定NVIC线路使能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//指定NVIC线路的抢占优先级为2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//指定NVIC线路的响应优先级为1
	NVIC_Init(&NVIC_InitStructure);								//将结构体变量交给NVIC_Init，配置NVIC外设

    TIM2->CR1 |= (1<<0);        //使能定时器
}







