#include "stm32f10x.h"
#include "CHAL.h"
#include "OLED.h"

uint16_t Num;
int main (void)
{
    // CHAL_LedInit();
	OLED_Init();
	Timer2_Init();
	/*显示静态字符串*/
	OLED_ShowString(1, 1, "Num:");			//1行1列显示字符串Num:
	while(1)
	{
        // CHAL_LedFlow();
		// CHAL_Buzzer();
		// CHAL_LedKey();
		OLED_ShowNum(1, 5, Num, 5);			//不断刷新显示Num变量
	}
}

/**
  * 函    数：TIM2中断函数
  * 参    数：无
  * 返 回 值：无
  * 注意事项：此函数为中断函数，无需调用，中断触发后自动执行
  *           函数名为预留的指定名称，可以从启动文件复制
  *           请确保函数名正确，不能有任何差异，否则中断函数将不能进入
  */
void TIM2_IRQHandler(void)
{
	if ((TIM2->SR & 0x1) && (TIM2->DIER & 0x1))		//判断是否是TIM2的更新事件触发的中断
	{
		Num ++;					//Num变量自增，用于测试定时中断
		TIM2->SR &= ~(1<<0);    //清除中断标志位
	}
}

