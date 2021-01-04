#include <string.h>
#include "sys.h"
#include "delay.h"
#include "led.h"
#include "mpu9250.h"
/********************************************************************************	 
 * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
 * ALIENTEK MiniFly
 * main.c	
 * ����ԭ��@ALIENTEK
 * ������̳:www.openedv.com
 * ��������:2017/5/2
 * �汾��V1.0
 * ��Ȩ���У�����ؾ���
 * Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
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



