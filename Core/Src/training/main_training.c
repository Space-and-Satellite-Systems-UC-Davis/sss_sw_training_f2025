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

#define LED_PORT GPIOC
#define LED_PIN  13

void my_task(void * pvParameters) {
	configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

	int count = 0;
	for(;;) {
		printMsg("Hello #%d\r\n", count++);
	}
}

int main(void)
{
	setup_training();
	int count = 0;

	BaseType_t xReturned;
	TaskHandle_t xHandle = NULL;

	xReturned = xTaskCreate(
			my_task,
			"LOL",
			32,
			(void *) 1,
			tskIDLE_PRIORITY,
			&xHandle
	);

	vTaskStartScheduler();

	if(xReturned == pdPASS) {
		vTaskDelete( xHandle );
	}
}

