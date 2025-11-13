/*
 * main_training.c
 *
 *  Created on: Sep 22, 2025
 *      Author: dilgill
 */

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "main.h"

#include "pid.h"

#define LED_PORT GPIOC
#define LED_PIN  13

int main(void)
{
	setup_training();

	PID pid =
	{
		.Kp = 1.0,
		.Ki = 0.0,
		.Kd = 0.0,

		.tau = 0.1,

		.out_min = -25.0,
		.out_max =  +25.0,

		.int_min = -5.0,
		.int_max =  5.0,

		.dt = 0.05,
	};

	PID_Init(&pid);

	float setpoint = 5.0;
	TIM3->CCR1 = 18000;



	/* Infinite loop */
	while (1)
	{
	  HAL_Delay(50);

	  uint32_t enc_count = TIM2->CNT>>2;
	  float measurement = enc_count/700.0;

	  printMsg("Hello #%d\r\n", enc_count++);

	  float pct = PID_Update(&pid, setpoint, measurement);

	  uint32_t ccr_val = pct_to_ccr(pct);

	  TIM3->CCR1 = ccr_val;

	  int apple = 33;
	  apple++;
//	  printMsg("Setpoint: %d.%d\r\nCurrent: %d\r\nOutput: %f\r\n===================\r\n", setpoint, measurement, out);
	}
}

