#pragma once
#include "ros/ros.h"
#include <estimator/imu_data.h>
#include <estimator/human_inputs.h>
#include <estimator/barometer_data.h>
#include <estimator/quad_rotor_states.h>
#include <estimator/gps_data.h>
#include <Eigen/Dense>
#include "filter.h"

void imuCallBack(const estimator::imu_data::ConstPtr& msg);
void barometerCallBack(const estimator::barometer_data::ConstPtr& msg);
void inputCallBack(const estimator::human_inputs::ConstPtr& msg);
void gpsCallBack(const estimator::gps_data::ConstPtr& msg);

namespace sensors
{
	boost::array<float, 3> acc;
	boost::array<float, 3> gyr;
	boost::array<float, 3> mag;

	float gps_lat;
	float gps_long;
	float gps_height_sea_level;

	Eigen::Matrix<double, QuadRotorModel::num_outputs, 1> measurements;
	Eigen::Matrix<double, 4, 1> humanInputs;
	Eigen::Matrix<double, QuadRotorModel::num_states, 1> states;

	Filter kalmanFilter(.01);

	int height;
}
