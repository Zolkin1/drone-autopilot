#include "barometer.h"

int main(int argc, char **argv)
{
	barometer.initialize();

	ros::init(argc, argv, "barometer");
	ros::NodeHandle n;

	ros::Publisher bar_data_pub = n.advertise<estimator::barometer_data>("barometer_data", 100);
	estimator::barometer_data bar_data;
	//Set loop to 1 hz - might need to be changed
	ros::Rate loop_rate(1);

	while (ros::ok())
	{
		barometer.update(); //There is a thread sleep in this function call. Need to make sure this works
		bar_data.pressure = barometer.getPressure();
		bar_data.temperature = barometer.getTemperature(); //Change spelling

		bar_data_pub.publish(bar_data);

		ros::spinOnce();

		loop_rate.sleep();
	}
}