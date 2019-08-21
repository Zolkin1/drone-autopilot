#pragma once

#include <Eigen/Dense>
#include <array>
#include <fstream>
#include <iostream>

#include "thread_helpers.h"
#include "pid.h"
#include "constants.h"
#include "PWM.h"
#include "RCOutput_Navio.h"
#include "RCOutput_Navio2.h"
#include "Util.h"

using std::ofstream;

class quadRotorController
{
public:
	void control_to_state(uint8_t * current_state, uint8_t * desired_state);//struct state_struct current_state, struct state_struct desired_state);
	//void control_to_state_velocity(struct state_struct current_state, struct state_struct desired_state); //Need to add in velocity
	quadRotorController();
	void close_debug_file();

private:
	pid rollPID;
	pid pitchPID;
	pid yawPID;
	pid thrustPID;

	float roll;
	float pitch;
	float yaw;
	float thrust;

	static constexpr float _dt = 1/250;

	RCOutput_Navio2 pwm;

	FILE * debug_file_rpy;
	FILE * debug_file_motors;

	std::array<int, 4> duty_cycles;
	std::array<float, 4> controller_efforts;

	Eigen::Vector4f states_to_motors_transform(float roll, float pitch, float yaw, float thrust);
	int write_motor(int motor, int duty_cycle);

};