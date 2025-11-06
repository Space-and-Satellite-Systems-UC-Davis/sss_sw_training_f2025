/*
 * gpio.c
 *
 * FOR SSS SOFTWARE FALL 2025 TRAINING
 *
 *
 *  Created on: Sep 21, 2025
 *      Author: nithinsenthil
 */

#include "gpio_training.h"

void gpio_high(GPIO_TypeDef *port, int pin) {
	port->BSRR |= (1U << pin);
}

void gpio_low(GPIO_TypeDef *port, int pin) {
	port->BSRR |= (1U << (pin+16));
}	

void gpio_set(GPIO_TypeDef *port, int pin, GPIO_VALUE value) {
	if (GPIO_LOW) gpio_low(port, pin);
	else gpio_high(port, pin);
}

void gpio_configureMode(GPIO_TypeDef *port, int pin, GPIO_CNF cnf, GPIO_MODE mode) {
	if (pin <= 7) { // 0 - 7
		port->CRL |= (mode << (pin * 4));
		port->CRL |= (cnf << (2 + pin * 4));
	} else { // 7 - 15
		port->CRH |= (mode << ((pin-8) * 4));
		port->CRH |= (cnf << (2 + (pin-8) * 4));
	}
}

/*
 * Pls don't modify cause I will be sad D:
 */
void rcc_enable(RCC_SELECT reg) {
	RCC->APB2ENR |= reg;
}

