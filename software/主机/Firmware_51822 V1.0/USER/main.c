#include <string.h>
#include "nrf.h"
#include "nrf_gpio.h"
#include "led.h"
#include "button.h"
#include "systick.h"
/********************************************************************************	 
 * 本程序只供学习使用，未经作者许可，不得用于其它任何用途
 * ALIENTEK MiniFly
 * main.c	
 * 包括系统初始化和通信处理
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
	/*等待外部晶振起振*/
    NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;
    NRF_CLOCK->TASKS_HFCLKSTART    = 1;
    while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0);
	  LED_INIT();
	  LED_OFF();
		systickInit();		
		buttonInit(buttonIdle);
	
		nrf_gpio_cfg_output(PM_VCCEN_PIN);
	  nrf_gpio_pin_clear(PM_VCCEN_PIN);		//关闭stm32电源
	  msDelay(100);
	
		while(1)
		{
			buttonEvent_e be = buttonGetState();//获取按键
			if(be == buttonShortPress)
			{
				LED_OFF();	
				nrf_gpio_pin_clear(PM_VCCEN_PIN);//关闭stm32电源
			}
			else if(be == buttonLongPress)
			{
				LED_ON();
				nrf_gpio_pin_set(PM_VCCEN_PIN);		//使能stm32电源
			}
			buttonProcess();
		}
}



