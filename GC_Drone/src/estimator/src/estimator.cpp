#include "estimator.h"


using namespace sensors;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "estimator");
	ros::NodeHandle n;

	ros::Subscriber imuSub = n.subscribe("imu_data", 1000, imuCallBack);
	ros::Subscriber barometerSub = n.subscribe("barometer_data", 1000, barometerCallBack);
	ros::Subscriber controlInputs = n.subscribe("human_inputs", 100, inputCallBack);
	ros::Subscriber gpsSub = n.subscribe("gps_data", 100, gpsCallBack);
	ros::Publisher est_state = n.advertise<estimator::quad_rotor_states>("estimated_states", 1000);

	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		printf("In estimator loop");

		//Maybe need to make initial senosr reading to get starting height and other such things?
		//Might want to calibrate sensors

		//Add states variable
		kalmanFilter.predict(humanInputs);
		//Might want to add check to prevent nans or other issues (if they become a problem)
		for (int i = 0; i < 3; i++)
		{
			measurements(i, 0) = gyr.at(i);

			//TODO: Implement GPS data
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

void inputCallBack(const estimator::human_inputs::ConstPtr& msg)
{
	for (int i = 0; i < 4; i++)
	{
		humanInputs(i, 0) = msg->inputs.at(i);
	}
}

//TODO: propogate gps accuracies through to the kalman filter sensor covariances
//TODO: propogate the tow through to the kalman filter to get a more accurate dt for better velocities
void gpsCallBack(const estimator::gps_data::ConstPtr& msg)
{
	gps_long = msg->longitude;
	gps_lat =  msg->latitude;
	gps_height_sea_level = msg->height_above_sea_level;
}