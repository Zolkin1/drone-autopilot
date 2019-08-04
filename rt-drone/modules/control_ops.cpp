/**
This the main controller thread.
This is responsible for:
	- Reading the IMU, gps, and barometer data
	- Filtering sensor data
	- Estimating states with sensor data
	- Calculating control inputs
	- Communicating with hardware i.e. pwm outs

Right now, this node will attempt to be run around 200hz. This means that loop run time should be
less than 2ms.
**/


