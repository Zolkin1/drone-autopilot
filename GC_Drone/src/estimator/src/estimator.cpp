#include "ros/ros.h"
#include <estimator/imu_data.h>

void imuCallBack(const estimator::imu_data::ConstPtr& msg);

//Declare global variables
boost::array<float, 3> acc;
boost::array<float, 3> gyr;
boost::array<float, 3> mag;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "estimator");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("imu_data", 1000, imuCallBack);

	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		//printf("In estimator loop");

		ros::spinOnce();

		loop_rate.sleep();
	}

	return 0;
}

//Recieve IMU data, parse it elsewehere
void imuCallBack(const estimator::imu_data::ConstPtr& msg)
{
	//this size might be wrong, could hardcode 3
	for (int i = 0; i < size(msg->acceleration); i++)
	{
		acc.at(i) = msg->acceleration.at(i);
		gyr.at(i) = msg->gyro.at(i);
		mag.at(i) = msg->magentometer.at(i);
	}
}