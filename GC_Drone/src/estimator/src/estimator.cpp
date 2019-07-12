#include "estimator.h"


using namespace sensors;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "estimator");
	ros::NodeHandle n;

	ros::Subscriber imuSub = n.subscribe("imu_data", 1000, imuCallBack);
	ros::Subscriber barometerSub = n.subscribe("barometer_data", 1000, barometerCallBack);
	ros::Subscriber controlInputs = n.subscribe("human_input", 100, inputCallBack);
	//ros::Publisher est_state = n.advertise<estimator::quad_rotor_states>("estimated_states", 1000);

	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		printf("In estimator loop");

		//TODO: Implement the filter class
		//Add states variable
		kalmanFilter.predict(humanInputs);
		for (int i = 0; i < 3; i++)
		{
			measurements(i, 0) = gyr.at(i);
			//Still need to add gps data in
			//measurements(i+3, 0) = gps.at(i);
		}
		states = kalmanFilter.update(measurements);

		//est_state.advertise(states);

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

//Recieves Barometer Data
void barometerCallBack(const estimator::barometer_data::ConstPtr& msg)
{
	height = msg->height;
}

void inputCalBack(const estimator::human_inputs::ConstPtr& msg)
{
	for (int i = 0; i < 4; i++)
	{
		humanInputs(i, 0) = msg->inputs.at(i);
	}
}