#include "controller.h"

Controller::Controller(Eigen::Matrix<float, 6, 1> K, Vector12f initialEstimatedState)
{
	fK = K;
	fEstimatedState = initialEstimatedState;
	fDesiredState = initialEstimatedState;
}

Controller::Controller()
{
	//fK = Eigen::Matrix<float, 6, 1> K;
	fK << 0,0,0,0,0,0;
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

void setK(Eigen::Matrix<float, 6, 1> K)
{
	fK = K;
}

Eigen::Matrix<float, 4, 1> Controller::getInputs()
{
	
}

float Controller::getDesiredThrust()
{

}