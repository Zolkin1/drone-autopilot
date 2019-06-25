#pragma once
#include <Eigen/Dense>
#include <estimator/quad_rotor_states.h>

typedef Eigen::Matrix<float, 12, 1> Vector12f;

class Controller
{
private:

	Vector12f fEstimatedState;
	Vector12f fDesiredState;
	
	//Optimal feedback matrix based on LQR. Need to get the correct dimensions.
	//Also need to get the correct values.
	Eigen::Matrix<float, 4, 12> fK;

public:
	Controller(Eigen::Matrix<float, 4, 12> K, Vector12f initialEstimatedState);
	Controller();

	void setDesiredState(const estimator::quad_rotor_states::ConstPtr& msg);
	void setEstimatedState(const estimator::quad_rotor_states::ConstPtr& msg);
	void setK(Eigen::Matrix<float, 4, 12> K);
	
	Eigen::Vector4f getInputs();
	~Controller();
};