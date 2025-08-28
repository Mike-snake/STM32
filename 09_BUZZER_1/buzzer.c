/*
 * buzzer.c
 *
 *  Created on: Mar 24, 2025
 *      Author: USER
 */


#include "buzzer.h"
#include "delay.h"

#include <stdbool.h>

  uint16_t song[] = {Mi, Do};
//  uint16_t song[] = {Do, Re, Mi, Fa, Sol, Ra, Si, Do1};
  uint16_t time[] = {qNote, wNote};

void buzzer_on()
{

	  for(uint16_t i=0; i<= sizeof(song); i++)
	  {
		  TIM4->PSC = song[i];
		  for(uint16_t j=0; j<1000; j++)
		  {
			  delay_us(time[i]);
		  }
		  TIM4->CCR1 = 0;
		  delay_us(5000);
		  TIM4->CCR1 = 500;
	  }

//	  TIM4->CCR1 = 0;
//	TIM4->PSC = 110;
//  for(uint16_t i=0; i<10; i++)
//	  delay_us(60000);
//  TIM4->CCR1 = 0;
//  delay_us(60000);
//  TIM4->CCR1 = 500;
//
//  TIM4->PSC = 391;
//  for(uint16_t i=0; i<10; i++)
//	  delay_us(60000);
//  TIM4->CCR1 = 0;
//
//  delay_us(60000);
//  TIM4->CCR1 = 500;
//
//  TIM4->CCR1 = 0;
/*
  for(uint16_t i=0; i<10; i++)
	  delay_us(60000);

  uint16_t song[] = {Re, Do1};
  //uint16_t time[] = {qNote, wNote};

  TIM4->PSC = song[0];
  delay_us(20000);
  TIM4->CCR1 = 0;
  delay_us(20000);
  TIM4->CCR1 = 500;


  delay_us(50000);

  TIM4->PSC = song[1];
  delay_us(20000);

  TIM4->CCR1 = 0;
  delay_us(20000);
  TIM4->CCR1 = 500;



	  TIM4->PSC = 383; //도
	  HAL_Delay(600);  //음표길이
	  TIM4->CCR1 = 0;
	  HAL_Delay(10);
	  TIM4->CCR1 = 500;

	  TIM4->PSC = 130; //미
	  HAL_Delay(600);  //음표길이

	  TIM4->CCR1 = 0;

	  HAL_Delay(10);
	  TIM4->CCR1 = 500;


	  TIM4->PSC = 355; //솔
	  HAL_Delay(600);  //음표길이
	  TIM4->CCR1 = 0;
	  HAL_Delay(10);
	  TIM4->CCR1 = 500;
*/




}


void buzzer_off()
{
	delay_us(60000);
	TIM4->CCR1 = 0;

}



