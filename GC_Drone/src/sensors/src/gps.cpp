#include "gps.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "gps");
	ros::NodeHandle n;

	ros::Publisher gps_data_pub = n.advertise<estimator::gps_data>("gps_data", 100);
	estimator::gps_data gps_data;
	//Set loop to 1 hz - might need to be changed
	ros::Rate loop_rate(2);

	if (gps.testConnection())
	{
		if (!gps.configureSolutionRate(1000))
		{
        	printf("Setting new rate: FAILED\n");
    	}

		while (ros::ok())
		{
			if (gps.decodeSingleMessage(Ublox:;NAV_POLLH, pos_data) == 1)
			{
				gps_data.tow = pos_data[0]/1000;
				gps_data.longitude = pos_data[1]/10000000;
				gps_data.latitude = pos_data[2]/10000000;
				gps_data.height_above_ellipsoid = pos_data[3]/1000;
				gps_data.heigt_above_sea_level = pos_data[4]/1000;
				gps_data.horizontal_accuracy = pos_data[5]/1000;
				gps_data.vertical_accuracy = pos_data[6]/1000;

				gps_data_pub.publish(gps_data);
			}

			loop_rate.sleep();
		}
	}
}