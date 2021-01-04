#include <string.h>
#include "sys.h"
#include "delay.h"
#include "led.h"
#include "mpu9250.h"
/********************************************************************************	 
 * 本程序只供学习使用，未经作者许可，不得用于其它任何用途
 * ALIENTEK MiniFly
 * main.c	
 * 正点原子@ALIENTEK
 * 技术论坛:www.openedv.com
 * 创建日期:2017/5/2
 * 版本：V1.0
 * 版权所有，盗版必究。
 * Copyright(C) 广州市星翼电子科技有限公司 2014-2024
 * All rights reserved
********************************************************************************/

int main()
{

	delay_init(96);
	ledInit();
	MPU9250_Init();
//	GPIO_SetBits(GPIOA,GPIO_Pin_5);
	while(1) 
	{	
			LED_BLUE_L =1;
			delay_ms(1000);
			LED_BLUE_L =0;
			delay_ms(1000);
	}
}



