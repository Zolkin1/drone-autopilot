#include "ros/ros.h"
#include <estimator/imu_data.h>
#include <Eigen/Dense>
#include "quad_rotor_model.h"

class Filter 
{
	private:
		Eigen::Matrix<double, QuadRotorModel::num_states, 1> current_state;
		Eigen::Matrix<double, QuadRotorModel::num_states, 1> estimated_state;

		Eigen::Matrix<double, QuadRotorModel::num_states, QuadRotorModel::num_states> F; //State transition model (A in state space form)
		Eigen::Matrix<double, QuadRotorModel::num_states, QuadRotorModel::num_outputs> B; //Contol input model
		Eigen::Matrix<double, QuadRotorModel::num_outputs, QuadRotorModel::num_states> H; //Observaiton model
		Eigen::Matrix<double, QuadRotorModel::num_states, QuadRotorModel::num_states> Q; //Covariance of process noise
		Eigen::Matrix<double, QuadRotorModel::num_outputs, QuadRotorModel::num_outputs> R; //Covariance of observation noise
		Eigen::Matrix<double, QuadRotorModel::num_states, QuadRotorModel::num_states> P; //Estimate Covariance

		Eigen::Matrix<double, QuadRotorModel::num_states, QuadRotorModel::num_states> I; //Identity matrix

		float fdt;

	public:
		Filter(float dt);

		//Predict after each change in motor input
		void predict(Eigen::Matrix<double, 4, 1> inputs);
		//Update after each measurement - acts as multi rate senspr fusion
		Eigen::Matrix<double, QuadRotorModel::num_states, 1> update(Eigen::Matrix<double, QuadRotorModel::num_outputs, 1> measurements);

		Eigen::Matrix<double, QuadRotorModel::num_states, 1> getState();
};
