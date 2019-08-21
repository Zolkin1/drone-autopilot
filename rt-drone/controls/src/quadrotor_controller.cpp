#include "quad_rotor_controller.h"

quadRotorController::quadRotorController() : rollPID(1, 0, 0, 0, _dt), pitchPID(1, 0, 0, 0, _dt), yawPID(1, 0, 0, 0, _dt), thrustPID(1, 0, 0, 0, _dt), pwm()
{
	//rpy_debug = fopen("rpy_logs.txt", "w"); //Make it log to a "data" folder. User might not be "pi"   
	//motor_debug = fopen("motors_logs.txt", "w");
}

void quadRotorController::control_to_state(struct state_struct current_state, struct state_struct desired_state)
{
   

	roll = rollPID.calculatePID(desired_state.roll - current_state.roll);
	pitch = pitchPID.calculatePID(desired_state.pitch - current_state.pitch);
	yaw = yawPID.calculatePID(desired_state.yaw - current_state.yaw);
	thrust = thrustPID.calculatePID(desired_state.thrust - current_state.thrust);

	printf("controls logging to rpy file. \n");
	fprintf(rpy_debug, "%f %f %f %f \n", (float)roll, (float)pitch, (float)yaw, (float)thrust);

	//Need to convert then into vel space because that is what the motor speed controls. Maybe. Try this first.
	
	// Transform to motor space here
	Eigen::Vector4f motor_inputs = states_to_motors_transform(roll, pitch, yaw, thrust);
	printf("controls logging to motor debug. \n");
	fprintf(motor_debug, "%f %f %f %f\n", (float)motor_inputs(0), (float)motor_inputs(1), (float)motor_inputs(2), (float)motor_inputs(3));

	// Output is duty cycle vector float

	for (int i = 0; i < 4; i++)
	{
		motor_inputs(i) /= MAX_MOTOR_SPEED;

		// Saturate if greater than 1
		if (std::abs(motor_inputs(i)) > 1)
		{
			motor_inputs(i) = std::copysign(1, motor_inputs(i));
		}

		int duty_cycle = (int)(motor_inputs(i) * (MAX_DUTY_CYCLE - MIN_DUTY_CYCLE)) + MIN_DUTY_CYCLE;
		
		write_motor(i, duty_cycle);
	}
}

void quadRotorController::control_to_state_velocity(struct state_struct current_state, struct state_struct desired_state) //Need to add in velocity
{
	roll = rollPID.calculatePID(desired_state.roll - current_state.roll);
	pitch = pitchPID.calculatePID(desired_state.pitch - current_state.pitch);
	yaw = yawPID.calculatePID(desired_state.yaw - current_state.yaw);
	thrust = thrustPID.calculatePID(desired_state.thrust - current_state.thrust);

	//Need to convert then into vel space because that is what the motor speed controls. Maybe. Try this first.
	
	// Transform to motor space here
	Eigen::Vector4f motor_inputs = states_to_motors_transform(roll, pitch, yaw, thrust); //Might not be the correct type

	// Output is duty cycle vector float

	for (int i = 0; i < 4; i++)
	{
		motor_inputs(i) /= MAX_MOTOR_SPEED;
		
		// Saturate if greater than 1
		if (std::abs(motor_inputs(i)) > 1)
		{
			motor_inputs(i) = std::copysign(1, motor_inputs(i));
		}

		int duty_cycle = (int)(motor_inputs(i) * (MAX_DUTY_CYCLE - MIN_DUTY_CYCLE)) + MIN_DUTY_CYCLE;
		
		write_motor(i, duty_cycle);
	}
}

Eigen::Vector4f quadRotorController::states_to_motors_transform(float roll, float pitch, float yaw, float thrust)
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

	//Need to determine these constants
	float b = 1;
	float l = 1;
	float d = 1;

	Eigen::Matrix4f A;
	A << b, b, b, b,
		-b*l, 0.0, b*l, 0.0,
		0.0, -b*l, 0.0, b*l,
		-d, d, -d, d;
	
	Eigen::Matrix4f invA = A.inverse();

	Eigen::Vector4f control_inputs(thrust, roll, pitch, yaw);

	//This calculation could be slow. Might want to change it if it causing issues
	Eigen::Vector4f sol = invA.lu().solve(control_inputs);
	return sol;
}

int quadRotorController::write_motor(int motor, int duty_cycle)
{
	if( !(pwm.initialize(motor)) ) 
	{
        return 1;
    }

	pwm.set_frequency(motor, 50); //50 hardcoded to be motor frequency
	pwm.set_duty_cycle(motor, duty_cycle);
}

void quadRotorController::close_debug_file()
{
	printf("Closing quadrotor controls files\n");
	fclose(debug_file_motors);
	fclose(debug_file_rpy);
}

