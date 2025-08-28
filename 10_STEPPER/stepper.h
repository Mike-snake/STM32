/*
 * stepper.h
 *
 *  Created on: Mar 21, 2025
 *      Author: USER
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_



#include "main.h"
#include "delay.h"



#define STEPS_PER_REVOLUTION  4096  // 하프 스텝
#define DIR_CW				  0  // 시계 방향
#define DIR_CCW				  1  // 반시계 방향 (COUNTER CLOCK WIRE)



#define IN1_Pin				  GPIO_PIN_1
#define IN1_GPIO_Port		  GPIOB
#define IN2_Pin				  GPIO_PIN_15
#define IN2_GPIO_Port		  GPIOB
#define IN3_Pin				  GPIO_PIN_14
#define IN3_GPIO_Port		  GPIOB
#define IN4_Pin				  GPIO_PIN_13
#define IN4_GPIO_Port		  GPIOB


static const uint8_t HALF_STEP_SEQ[8][4] =
{
		{1, 0, 0, 0},
		{1, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 1},
		{0, 0, 0, 1},
		{1, 0, 0, 1},
};


void stepMotor(uint8_t step);
void rotateSteps(uint16_t steps, uint8_t direction);
void rotateDegrees(uint16_t degrees, uint8_t direction);





#endif /* INC_STEPPER_H_ */
