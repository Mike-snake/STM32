/*
 * led.c
 *
 *  Created on: Mar 17, 2025
 *      Author: USER
 */

#include "led.h"


LED_CONTROL led[8]=
{
		{GPIOA, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET},		// PORTA0
		{GPIOA, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},		// PORTA1
		{GPIOA, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOB, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOC, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOA, GPIO_PIN_9, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOA, GPIO_PIN_8, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOB, GPIO_PIN_10, GPIO_PIN_SET, GPIO_PIN_RESET},

};



void ledOn(uint8_t num)		// 한꺼번에 켬
{
	for(uint8_t i=0; i < num; i++)
	{
		HAL_GPIO_WritePin(led[i].port, led[i].pinNumber, led[i].onState);
	}
//	HAL_GPIO_WritePin(led[num].port, led[num].pinNumber, led[num].onState);
}

void ledOff(uint8_t num)	// 한꺼번에 끔
{
	for(uint8_t i = 0; i < num; i++)
	{
		HAL_GPIO_WritePin(led[i].port, led[i].pinNumber, led[i].offState);
	}
}

void ledToggle(uint8_t num)		// 지정된 핀만 토글
{
	HAL_GPIO_TogglePin(led[num].port, led[num].pinNumber);

}

void ledLeftShift(uint8_t num)
{
	for(uint8_t i = 0; i < num; i++)
	{
		ledOn(i);
		HAL_Delay(100);
	}

	HAL_Delay(500);

	for(uint8_t i = 0; i < num; i++)
	{
		ledOff(i);

	}
	HAL_Delay(500);

}

void ledRightShift(uint8_t num)
{

	for(uint8_t i=num; i>0; i--)
	{
		ledOn(i);
		ledOff(i-1);
		HAL_Delay(300);
	}

	for(uint8_t i=num; i>0; i--)
	{
		ledOff(i);
		ledOn(i-1);
		HAL_Delay(300);
	}
	HAL_Delay(500);


}

void ledFlower(uint8_t num){

	for(uint8_t i = 5; i <= num; i++)
	{
		ledOn(i);
		ledOff(num - i);
		HAL_Delay(300);
	}
	ledOff(num);
	HAL_Delay(500);

}


