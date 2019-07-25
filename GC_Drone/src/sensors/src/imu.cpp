#include "ros/ros.h"
#include <estimator/imu_data.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "imu");
	ros::NodeHandle n;

	ros::Publisher imu_data_pub = n.advertise<estimator::imu_data>("imu_data", 1000);
	//Set loop to 100 hz
	ros::Rate loop_rate(100);


	estimator::imu_data msg;
	for (int i = 0; i < 4; i++)
	{
		msg.acceleration.at(i) = i;
		msg.gyro.at(i) = i;
		msg.magentometer.at(i) = i;
	} 

	while (ros::ok())
	{
		//printf("In IMU loop");

		imu_data_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
	}

	return 0;
}