/*
 * ultrasoic.c
 *
 *  Created on: Mar 19, 2025
 */

#include "ultrasonic.h"

static uint16_t IC_Value1 = 0;  // 에코핀이 하이엣지 일때
static uint16_t IC_Value2 = 0;  // 에코핀이 로우엣지 일때
static uint16_t echoTime = 0;  //에코핀의 하이엣지와 로우엣지 사이의 시간(카운드 갯수)
static uint8_t captureFlag = 0;  //
uint8_t distance = 0;   // 거리



void HCRSC04_Trigger(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	delay_us(1);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
	delay_us(10);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);


	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_CC1);

}



void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if(captureFlag == 0)		// 아직 캡처 안 했으면
		{
			// 첫번째 밸류에 캡처 인터럽트가 발생하면 카운트 값을 가져옴
			IC_Value1 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
			captureFlag = 1;		//캡쳐 했다고 플래그 세움

			__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);

		}

		else if(captureFlag == 1)			// 한번 캡처 했으면
		{
			IC_Value2 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
			__HAL_TIM_SET_COUNTER(&htim3, 0);


			if(IC_Value2 > IC_Value1)
			{
				echoTime = IC_Value2 - IC_Value1;


			}
			else if(IC_Value1 > IC_Value2)
			{

				echoTime = (0xfff - IC_Value1) + IC_Value2;



			}

			//
			distance = echoTime / 58;
			captureFlag = 0;

			__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);

		}

	}



//	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
//	{
//		if(captureFlag1 == 0)		// 아직 캡처 안 했으면
//		{
//			// 첫번째 밸류에 캡처 인터럽트가 발생하면 카운트 값을 가져옴
//			IC_Value3 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_2);
//			captureFlag1 = 1;		//캡쳐 했다고 플래그 세움
//
//			__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
//
//		}
//
//		else if(captureFlag1 == 1)			// 한번 캡처 했으면
//		{
//			IC_Value4 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_2);
//			__HAL_TIM_SET_COUNTER(&htim3, 0);
//
//
//			if(IC_Value4 > IC_Value3)
//			{
//				echoTime = IC_Value4 - IC_Value3;
//
//
//			}
//			else if(IC_Value3 > IC_Value4)
//			{
//
//				echoTime1 = (0xfff - IC_Value3) + IC_Value4;
//
//
//
//			}
//
//			//
//			distance1 = echoTime1 / 58;
//			captureFlag1 = 0;
//
//			__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);
//			__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC2);
//
//		}
//
//
//	}

}





