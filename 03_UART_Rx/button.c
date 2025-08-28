/*
 * button.c
 *
 *  Created on: Mar 18, 2025
 *      Author: USER
 */


#include "button.h"




//bool buttonInit()
//{
//bool ret = true;
//return ret;
//}


BUTTON_CONTROL button[3] =
{
		{GPIOC, GPIO_PIN_8, 0},
		{GPIOC, GPIO_PIN_6, 0},
		{GPIOC, GPIO_PIN_5, 0}  //풀업 저항이기 때문에 누르면 0, 켜진다는 뜻의 온스테이드가 아니다.
};





bool buttonGetPressed(uint8_t num)
{
	static uint32_t prevTime = 0xFFFFFFFF;		//초기 값을 큰 값으로 설정

	if (prevTime == 0xFFFFFFFF)
	{
		prevTime = HAL_GetTick();
	}

	bool ret = false;

	uint32_t currTime = HAL_GetTick();

	if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
	{
		//HAL_Delay(10);  // 디바운스 코드 대신 넣어줌
		if(currTime - prevTime > 50)
		{
			if(HAL_GPIO_ReadPin(button[num].port, button[num].pinNumber) == button[num].onState)
			{
				ret = true;
			}
			prevTime = currTime;

		}
	}
	return ret;





}



