#include "ros/ros.h"
#include <estimator/quad_rotor_states.h>
#include <estimator/imu_data.h>
#include <estimator/motor_commands.h>
#include "controller.h"

Controller mainController;

namespace controller
{
	Eigen::Matrix<float, 6, 1> K;
    Eigen::Vector4f controlInputs;
    Eigen::Vector4f speeds;
    boost::array<float, 4> dutyCycles;
}
