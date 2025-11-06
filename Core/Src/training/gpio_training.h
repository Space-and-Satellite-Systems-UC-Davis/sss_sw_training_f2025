/*
 * gpio.h
 *
 * [FOR SSS SOFTWARE FALL 2025 TRAINING]
 *
 * Use this header to guide the implementation of the Blue Pill's GPIO drivers
 * in gpio.c. You should not NEED to make any changes in this document, but feel
 * free to make changes as you see fit. Happy... driverin... driving?!
 *
 *  Created on: Sep 21, 2025
 *      Author: nithinsenthil
 */

#ifndef SRC_GPIO_GPIO_H_
#define SRC_GPIO_GPIO_H_

// All the register address and mask macros are provided by ST,
// for the GPIO driver we will need the following file
#include "stm32f1xx.h"

// ----- Options for gpio configurations
// Derived from information in the programming manual

// options for GPIO Value
enum GPIO_VALUE {
    GPIO_LOW  = 0,
    GPIO_HIGH = 1
};
typedef enum GPIO_VALUE GPIO_VALUE;

// options for GPIO CNF
enum GPIO_CNF {
    GPIO_OUTPUT_PUSH_PULL  	= 0,
    GPIO_OUTPUT_OPEN_DRAIN 	= 1,
	GPIO_AF_PUSH_PULL		= 2,
	GPIO_AF_OPEN_DRAIN		= 3, 
	GPIO_INPUT_ANALOG		= 0,
	GPIO_INPUT_FLOATING		= 1,
	GPIO_INPUT_PULL_DOWN	= 2,
	GPIO_INPUT_PULL_UP		= 2,

	GPIO_DEFAULT_OPEN_DRAIN = GPIO_OUTPUT_PUSH_PULL
};
typedef enum GPIO_CNF GPIO_CNF;

// options for GPIO Mode
enum GPIO_MODE {
    GPIO_INPUT  	= 0,
	GPIO_MED_SPEED 	= 1, // Max 10 MHz
	GPIO_LOW_SPEED  = 2, // Max 2 MHz
	GPIO_HI_SPEED 	= 3, // Max 50 MHz

    GPIO_DEFAULT_MODE = GPIO_INPUT
};
typedef enum GPIO_MODE GPIO_MODE;

// options for GPIO RCC enable
enum RCC_SELECT  {
	GPIO_A_ENABLE	= RCC_APB2ENR_IOPAEN,
	GPIO_B_ENABLE	= RCC_APB2ENR_IOPBEN,
	GPIO_C_ENABLE	= RCC_APB2ENR_IOPCEN,
	GPIO_D_ENABLE	= RCC_APB2ENR_IOPDEN,
	GPIO_E_ENABLE	= RCC_APB2ENR_IOPEEN,
};
typedef enum RCC_SELECT RCC_SELECT;


// ----- GPIO Configurations

/**
 * Set the pin to high.
 * Usage: gpio_high(GPIOA, 1);  <-- That will set pin 1 of GPIOA to high
 *
 *
 * @param port GPIO port, ex. GPIOA
 * @param pin GPIO pin, ex. 1
*/
void gpio_high(GPIO_TypeDef *port, int pin);

/**
 * Set the pin to low.
 * Usage: gpio_low(GPIOA, 1);  <-- That will set pin 1 of GPIOA to low
 *
 *
 * @param port GPIO port, ex. GPIOA
 * @param pin GPIO pin, ex. 1
*/
void gpio_low(GPIO_TypeDef *port, int pin);

/**
 * Set the pin to a value.
 * Usage: gpio_set(GPIOA, 1, GPIO_HIGH);  <-- That will set pin 1 of GPIOA to high
 *
 *
 * @param port GPIO port, ex. GPIOA
 * @param pin GPIO pin, ex. 1
 * @param value GPIO_HIGH or GPIO_LOW
*/
void gpio_set(GPIO_TypeDef *port, int pin, GPIO_VALUE value);

/**
 * Configure the mode of the pin.
 * Usage: gpio_configureMode(GPIOA, 1, GPIO_OUTPUT_PUSH_PULL, GPIO_LOW_SPEED);  <-- That will set pin 1 of GPIOA to output mode, push-pull, low speed
 *
 *
 * @param port GPIO port, ex. GPIOA
 * @param pin GPIO pin, ex. 1
 * @param cnf See GPIO_CNF enum above for options
 * @param mode See GPIO_MODE enum above for options
*/
void gpio_configureMode(GPIO_TypeDef *port, int pin, GPIO_CNF cnf, GPIO_MODE mode);

/**
 * Enable GPIO peripheral clock
 * Usage: rcc_enable(GPIO_A_ENABLE);	<-- This will enable the GPIO A bank
 *
 *
 * @param reg See RCC_SELECT enum above for options
*/
void rcc_enable(RCC_SELECT reg);

#endif /* SRC_GPIO_GPIO_H_ */
