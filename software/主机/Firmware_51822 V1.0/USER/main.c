#include <string.h>
#include "nrf.h"
#include "nrf_gpio.h"
#include "led.h"
#include "button.h"
#include "systick.h"
/********************************************************************************	 
 * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
 * ALIENTEK MiniFly
 * main.c	
 * ����ϵͳ��ʼ����ͨ�Ŵ���
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
	/*�ȴ��ⲿ��������*/
    NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;
    NRF_CLOCK->TASKS_HFCLKSTART    = 1;
    while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0);
	  LED_INIT();
	  LED_OFF();
		systickInit();		
		buttonInit(buttonIdle);
	
		nrf_gpio_cfg_output(PM_VCCEN_PIN);
	  nrf_gpio_pin_clear(PM_VCCEN_PIN);		//�ر�stm32��Դ
	  msDelay(100);
	
		while(1)
		{
			buttonEvent_e be = buttonGetState();//��ȡ����
			if(be == buttonShortPress)
			{
				LED_OFF();	
				nrf_gpio_pin_clear(PM_VCCEN_PIN);//�ر�stm32��Դ
			}
			else if(be == buttonLongPress)
			{
				LED_ON();
				nrf_gpio_pin_set(PM_VCCEN_PIN);		//ʹ��stm32��Դ
			}
			buttonProcess();
		}
}



