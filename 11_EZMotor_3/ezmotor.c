/*
 * ezmotor.c
 *
 *  Created on: Mar 24, 2025
 *      Author: USER
 */

#include "ezmotor.h"

void ezmotor_on()
{
	TIM2->CCR1 = 70;
}


void ezmotor_off()
{
	TIM2->CCR1 = 0;
}
