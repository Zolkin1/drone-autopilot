/**
This the main controller thread.
This is responsible for:
	- Read sensor data from buffers - sensors can run in their own threads. 
	  Actually, maybe in the beginning just call sensor reads from here - worried about read times from hardware
	- Filtering sensor data
	- Estimating states with sensor data
	- Calculating control inputs
	- Communicating with hardware i.e. pwm outs

Right now, this node will attempt to be run around 200hz. This means that loop run time should be
less than 2ms.
**/

/*
Need to add sensor mutexes in.
*/

#include "control_ops.h"

void *control_ops_thread(void *data)
{
	printf("in control_ops");

	struct 	period_info pinfo;
	periodic_task_init(&pinfo, 1000000000);

    char temp_data_bytes[sizeof(float)];
    float temp;

    char * states_fifo = "/tmp/states_fifo";  // Not sure if this should be hardcoded
	int _states_fifo = open(states_fifo, O_RDONLY);
	if (_states_fifo < 0)
	{
		printf("Failed to open States FIFO. Exiting.");
		exit(-1);
	}

	while(1)
	{
		read(_states_fifo, temp_data_bytes, sizeof(float));
		memcpy(&temp, temp_data_bytes, sizeof(float));

		//Test to read data from sensors:
		printf("Temperature (C): %f\n", temp);
		wait_rest_of_period(&pinfo);
	}
}


