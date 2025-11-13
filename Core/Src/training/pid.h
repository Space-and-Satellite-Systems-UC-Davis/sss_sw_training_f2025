/*
 * pid.h
 *
 *  Created on: Nov 13, 2025
 *      Author: dilgill
 */

#ifndef SRC_TRAINING_PID_H_
#define SRC_TRAINING_PID_H_

typedef struct
{
	float Kp;
	float Ki;
	float Kd;

	float tau;

	float out_min;
	float out_max;

	float int_min;
	float int_max;

	float dt;

	float integral;

	float prev_error;
	float difference;
	float prev_measurement;

	float out;
} PID;

void PID_Init(PID* pid);
float PID_Update(PID* pid, float setpoint, float measurement);
uint32_t pct_to_ccr(float out);

#endif /* SRC_TRAINING_PID_H_ */
