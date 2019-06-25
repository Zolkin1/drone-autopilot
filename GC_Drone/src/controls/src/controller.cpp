/*
Currently uses an LQR control scheme. Probably move to a transfer function matrix. See top_level_controller.cpp for more details
*/
#include "controller.h"

Controller::Controller(Eigen::Matrix<float, 4, 12> K, Vector12f initialEstimatedState)
{
	fK = K;
	fEstimatedState = initialEstimatedState;
	fDesiredState = initialEstimatedState;
}

Controller::Controller()
{
	//fK = Eigen::Matrix<float, 6, 1> K;
	fK << 0,0,0,0,0,0,0,0,0,0,0,0,
		  0,0,0,0,0,0,0,0,0,0,0,0,
		  0,0,0,0,0,0,0,0,0,0,0,0,
		  0,0,0,0,0,0,0,0,0,0,0,0;
	fEstimatedState << 0,0,0,0,0,0,0,0,0,0,0,0;
	fDesiredState = fEstimatedState;
}

void Controller::setEstimatedState(const estimator::quad_rotor_states::ConstPtr& msg)
{
	for (int i = 0; i < msg->states.size(); i++)
	{
		fEstimatedState(i,1) = msg->states.at(i);
	}
}

void Controller::setDesiredState(const estimator::quad_rotor_states::ConstPtr& msg)
{
	for (int i = 0; i < msg->states.size(); i++)
	{
		fDesiredState(i,1) = msg->states.at(i);
	}
}

void Controller::setK(Eigen::Matrix<float, 4, 12> K)
{
	fK = K;
}

/*
returns vector of 4 floats:
	ft - thrust forces
	tx - torque around the x axis
	ty - torque around the y axis
	tz - torque around the z axis
*/
Eigen::Vector4f Controller::getInputs()
{
	Vector12f error = fDesiredState - fEstimatedState;
	Eigen::Vector4f controlInputs = fK * error;
	return controlInputs;

}

//Need to write the correct destructor
Controller::~Controller()
{
	//delete fEstimatedState;
	//delete fDesiredState;
	//delete fK;
}