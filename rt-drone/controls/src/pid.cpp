#include "pid.h"

pid::pid(float p, float i, float d, float dt, float sat_level)
{
	kp = p;
	ki = i;
	kd = d;
	_dt = dt;
	_sat_level = sat_level;

	accum_error = 0;
	prev_error = 0;
}

/*
@param the error
@out the control effort
*/
float pid::calculatePID(float error)
{
	// Need to add anti-windup in
	accum_error += error;
	float p = error * kp;
	float i = accum_error * ki;
	float d = (error-prev_error)/_dt * kd;

	float effort = p + i + d;

	// If sat_level is less than 0 then there is no anti-windup
	if (_sat_level > 0)
	{
		if (std::abs(effort) > _sat_level)
		{
			std::copysign(_sat_level, effort);
			effort = _sat_level;
		}
	}

	prev_error = error;

	return effort;
}