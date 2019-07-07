#include "ros/ros.h"
#include <estimator/imu_data.h>

void imuCallBack(const estimator::imu_data::ConstPtr& msg);
void barometerCallBack(const estimator::imu_data::ConstPtr& msg);

namespace sensors
{
	boost::array<float, 3> acc;
	boost::array<float, 3> gyr;
	boost::array<float, 3> mag;

	int height;
}
