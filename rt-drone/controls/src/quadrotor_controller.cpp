#include "quad_rotor_controller.h"

quadRotorController::quadRotorController()
{
	rollPID(1, 0, 0, 0, _dt);
	pitchPID(1, 0, 0, 0, _dt);
	yawPID(1, 0, 0, 0, _dt);
	thrustPID(1, 0, 0, 0, _dt);

}

void quadRotorController::control_to_state(struct state_struct current_state, struct state_struct desired_state); //Need to add in velocity
{
// Saturate if greater than 1
	if (std::abs(effort) > 1)
	{
		effort = std::copysign(1, effort);
	}

	int duty_cycle = (int)(effort * (quadRotorController::MAX_DUTY_CYCLE - quadRotorController::MIN_DUTY_CYCLE)) + quadRotorController::MIN_DUTY_CYCLE;
}

void quadRotorController::states_to_motors_transform(float roll, float pitch, float yaw, float thrust)
{
	/*
	Solve these equations:
	b is thrust factor
	l is distance from center of the drone to the rotor
	d is drag factor
	w is the speed of a rotor	
	ft = b(w1^2 + w2^2 + w3^2 w4^2)
	tx = bl(w3^2 - w1^2)
	ty = bl(w4^2 - -w2^2)
	tz = d(w2^2 + w4^2 - w1^2 - w3^2)
	
	return vector of w
	*/

	Eigen::Matrix4f A;
	A << b, b, b, b,
		-b*l, 0.0, b*l, 0.0,
		0.0, -b*l, 0.0, b*l,
		-d, d, -d, d;
	
	Eigen::Matrix4f invA = A.inverse();

	//This calculation could be slow. Might want to change it if it causing issues
	return invA.lu().solve(controlInputs);  
}
