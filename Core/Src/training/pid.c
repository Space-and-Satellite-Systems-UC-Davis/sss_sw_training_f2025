/*
 * pid.c
 *
 *  Created on: Nov 13, 2025
 *      Author: dilgill
 */

#include <stdint.h>
#include "pid.h"

void PID_Init(PID* pid) {
	pid->integral = 0.0;
	pid->prev_error = 0.0;

	pid->difference = 0.0;
	pid->prev_measurement = 0.0;

	pid->out = 0.0;
}


float PID_Update(PID* pid, float setpoint, float measurement) {
	float error = setpoint - measurement;

	float proportional = pid->Kp * error;

	pid->integral = pid->integral + (0.5 * pid->Ki * pid->dt * (error - pid->prev_error));

	if (pid->integral > pid->int_max) {
		pid->integral = pid->int_max;
	}
	else if (pid->integral < pid->int_min) {
		pid->integral = pid->int_min;
	}

	pid->difference = -(2.0 * pid->Kd * (measurement - pid->prev_measurement) + ( (2.0 * pid->tau - pid->dt) * pid->difference)/(2.0 * pid->tau + pid->dt));

	pid->out = proportional + pid->integral + pid->difference;

	if (pid->out > pid->out_max) {
		pid->out = pid->out_max;
	}
	else if (pid->out < pid->out_min) {
		pid->out = pid->out_min;
	}

	pid->prev_error = error;
	pid->prev_measurement = measurement;

	return pid->out;
}


uint32_t pct_to_ccr(float pct) {

	pct = pct/100;

	uint32_t out = (pct * 48000) + 18000;

	if(out < 48000/4) {
		out = 48000/4;
	} else if (out > 48000/2) {
		out = 48000/2;
	}

	return out;

}
