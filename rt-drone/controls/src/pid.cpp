#include "pid.h"

pid::pid(float p, float i, float d, float dt, float antiwindup)
{
	kp = p;
	ki = i;
	kd = d;
	_dt = dt;
	_antiwindup = antiwindup;

	accum_error = 0;
	prev_error = 0;
}

/*
@param the error
@out the control effort
*/
int pid::calculatePID(float error)
{
	// Need to add anti-windup in
	accum_error += error;
	float p = error * kp;
	float i = accum_error * ki;
	float d = (error-prev_error)/dt * kd;

	return p + i + d;
}