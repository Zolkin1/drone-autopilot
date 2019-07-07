#include "ros/ros.h"
#include <estimator/imu_data.h>
#include <Eigen/Dense>

class Filter 
{
	private:
		Eigen::Matrix<double, num_states, 1> current_state;
		Eigen::Matrix<double, num_states, 1> estimated_state;

		Eigen::Matrix<double, num_states, num_states> F; //State transition model (A in state space form)
		Eigen::Matrix<double, num_states, num_inputs> B; //Contol input model
		Eigen::Matrix<double, num_outputs, num_states> H; //Observaiton model
		Eigen::Matrix<double, num_states, num_states> Q; //Covariance of process noise
		Eigen::Matrix<double, num_outputs, num_outputs> R; //Covariance of observation noise
		Eigen::Matrix<double, num_states, num_states> P; //Estimate Covariance

		static float g = 9.81; //Gravitational Constant

	public:
		Filter(int dt);

		//Predict after each change in motor input
		void predict(Eigen::Matrix<double, num_inputs, 1> inputs);
		//Update after each measurement - acts as multi rate senspr fusion
		void update(Eigen::Matrix<double, num_outputs, 1> measurements);

		Eigen::Matrix<double, num_states, 1> getState();
