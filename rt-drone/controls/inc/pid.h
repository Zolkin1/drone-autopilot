#include <cmath>

class pid
{
private:
	float accum_error;
	float prev_error;
	float _dt;

public:
	float kp;
	float ki;
	float kd;
	float _antiwindup;

	float calculatePID(float error);
	pid(float p, float i, float d, float dt, float antiwindup);
}