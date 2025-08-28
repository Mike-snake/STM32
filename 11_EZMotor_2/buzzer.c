/*
 * buzzer.c
 *
 *  Created on: Mar 24, 2025
 *      Author: USER
 */


#include "buzzer.h"

void buzzer_on()
{

   /*
   TIM4->PSC = 310; //도
   HAL_Delay(300);  //음표길이
   TIM4->CCR1 = 0;
   HAL_Delay(1000);
   TIM4->CCR1 = 500;

   TIM4->PSC = 233; //도
   HAL_Delay(500);  //음표길이
   TIM4->CCR1 = 0;
   HAL_Delay(100);
   TIM4->CCR1 = 500;
   */






  TIM4->PSC = 142; //도
  //HAL_Delay(600);  //음표길이
  delay_us(60000);
  TIM4->CCR1 = 0;
  //HAL_Delay(1000);
  delay_us(10000);
  TIM4->CCR1 = 500;

  TIM4->PSC = 142; //도
  //HAL_Delay(600);  //음표길이
  delay_us(60000);
  TIM4->CCR1 = 0;
  //HAL_Delay(5);
  delay_us(50000);
  TIM4->CCR1 = 500;



  //HAL_Delay(600);
  delay_us(60000);
  TIM4->CCR1 = 0;
}




