#include "ros/ros.h"
#include <estimator/quad_rotor_states.h>
#include <estimator/imu_data.h>
#include <estimator/motor_commands.h>
#include <Eigen/Dense>
#include "header-files/PWM.h"
#include "header-files/RCOutput_Navio.h"
#include "header-files/RCOutput_Navio2.h"
#include "header-files/Util.h"
#include <unistd.h>
#include "controller.h"

//Declare all the mechanical constants here. i.e. length, weight, drag factor ect...
const float ARM_LENGTH = 1;
const float THRUST_FACTOR = 1;
const float DRAG_FACTOR = 0.1;
const float MAX_MOTOR_SPEED = 10; //Needs units and the correct value

#define SERVO_MIN 1000 /*mS*/ //0
#define SERVO_MAX 1500 /*mS*/ //1750

#define PWM_OUTPUT 0 //Specifies whhich hardware channel to use

bool fly;

Controller quadrotorController;

namespace controller
{
	Eigen::Matrix<float, 4, 12> K;
    Eigen::Vector4f controlInputs;
    Eigen::Vector4f speeds;
    estimator::motor_commands dutyCycles;
}

void updateState (const estimator::quad_rotor_states::ConstPtr& msg);
void changeTarget (const estimator::quad_rotor_states::ConstPtr& msg);
std::unique_ptr <RCOutput> get_rcout();

//Maybe move these to pass by refrence then have no returns
Eigen::Vector4f mapInputsToSpeed(Eigen::Vector4f controlInputs, float b, float l, float d);
void speedToDutyCycles(Eigen::Vector4f speeds);
auto pwm = get_rcout();

