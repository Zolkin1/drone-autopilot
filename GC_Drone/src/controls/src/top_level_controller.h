#include "ros/ros.h"
#include <estimator/quad_rotor_states.h>
#include <estimator/imu_data.h>
#include <estimator/motor_commands.h>
#include "controller.h"

//Declare all the mechanical constants here. i.e. length, weight, drag factor ect...
const float arm_length = 1;
const float thrust_factor = 1;
const float drag_factor = 0.1;
const float MAX_MOTOR_SPEED = 10; //Needs units and the correct value


Controller mainController;

namespace controller
{
	Eigen::Matrix<float, 6, 1> K;
    Eigen::Vector4f controlInputs;
    Eigen::Vector4f speeds;
    estimator::motor_commands dutyCycles;
}

void updateState (const estimator::quad_rotor_states::ConstPtr& msg);
void changeTarget (const estimator::quad_rotor_states::ConstPtr& msg);

//Maybe move these to pass by refrence then have no returns
Eigen::Vector4f mapInputsToSpeed(Eigen::Vector4f controlInputs, float b, float l, float d);
estimator::motor_commands speedToDutyCycles(Eigen::Vector4f speeds);

