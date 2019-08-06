#include "thread_helpers.h"
#include "pid.h"
#include <Eigen/Dense>

class quadRotorController
{
public:
	static const int MAX_DUTY_CYCLE = 1500;
	static const int MIN_DUTY_CYCLE = 1000;

	control_to_state(struct state_struct current_state, struct state_struct desired_state); //Need to add in velocity

private:
	pid rollPID();
	pid pitchPID();
	pid yawPID();
	pid thrustPID();

	static const float _dt = 1/250;

	void states_to_motors_transform(float roll, float pitch, float yaw, float thrust);

}