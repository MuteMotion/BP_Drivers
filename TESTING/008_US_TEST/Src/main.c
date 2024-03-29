/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "LCD_interface.h"
#include "US_interface.h"

int main(void)
{
	f32 distance=0;
	MCAL_RCC_InitSysClock();
	US_ID_t mid=Middle;
	US_config_t mid_conf={.DistanceRange=500,
						  .Echo_pin=GPIO_PIN1,
						  .Echo_port=GPIO_PORTB,
						  .Trigger_pin=GPIO_PIN2,
						  .Trigger_port=GPIO_PORTB,
						  .state=Ultrasonic_enable};
	MCAL_Rcc_EnablePrephiral(RCC_APB2_IOPAEN, RCC_APB2);
	LCD_Init();
	Ultrasonic_init(mid, &mid_conf);
	Ultrasonic_readDistance(mid, &distance);
	LCD_SendIntger(distance);
	for(;;)
	{

	}
}
