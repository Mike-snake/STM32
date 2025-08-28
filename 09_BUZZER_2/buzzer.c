/*
 * buzzer.c
 *
 *  Created on: Mar 24, 2025
 *      Author: USER
 */


#include "buzzer.h"
#include "delay.h"

#include <stdbool.h>



// 전역 변수
static BuzzerState buzzer_state = BUZZER_IDLE;
uint32_t buzzer_timer = 0;
uint8_t song_index = 0;

uint16_t song[3] = {Do, Mi, Sol};
//  uint16_t song[] = {Do, Re, Mi, Fa, Sol, Ra, Si, Do1};
//static uint16_t time[] = {qNote, wNote};

void buzzer_start()
{
    if (buzzer_state == BUZZER_IDLE)
    {
        song_index = 0;
        TIM4->PSC = song[song_index];
        TIM4->CCR1 = 500;  // PWM 듀티비 설정
        buzzer_timer = HAL_GetTick();
        buzzer_state = BUZZER_PLAYING;
    }
}

void buzzer_update()
{
    switch (buzzer_state)
    {
        case BUZZER_IDLE:
            // 아무 동작 없음
            break;

        case BUZZER_PLAYING:
            // 500ms 지나면 소리 끔 → REST 상태로
            if (HAL_GetTick() - buzzer_timer >= 500) {
                TIM4->CCR1 = 0;  // PWM OFF
                buzzer_timer = HAL_GetTick();
                buzzer_state = BUZZER_REST;
            }
            break;

        case BUZZER_REST:
            // 6ms 쉬고 다음 음 실행
            if (HAL_GetTick() - buzzer_timer >= 6) {
                song_index++;
                if (song_index < 3) {
                    // 다음 음 시작: 상태 바꾸고 소리 다시 켬
                    TIM4->PSC = song[song_index];
                    TIM4->CCR1 = 500;
                    buzzer_timer = HAL_GetTick();
                    buzzer_state = BUZZER_PLAYING;
                } else {
                    // 모든 음 재생 완료 → 종료
                    buzzer_state = BUZZER_IDLE;
                }
            }
            break;
    }
}



//void buzzer_on()
//{

//	  for(uint16_t i=0; i<3; i++)
//	  {
//		  buzzer_delay = HAL_GetTick();
//		  TIM4->CCR1 =500;
//		  TIM4->PSC = song[i];
//		  while(HAL_GetTick() - buzzer_delay < 500)
//		  {
//
//		  }
//		  TIM4->CCR1 = 0;
//		  while(HAL_GetTick() - buzzer_delay < 6)
//		  {
//
//		  }
//	  }

//}

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







void buzzer_off()
{
	delay_us(60000);
	TIM4->CCR1 = 0;

}



