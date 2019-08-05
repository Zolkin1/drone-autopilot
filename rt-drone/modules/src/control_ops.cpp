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
//#pragma once

#include <limits.h>
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <cerrno>

#include "control_ops.h"
#include "thread_helpers.h"


void *control_ops_thread(void *data)
{
	printf("in control_ops\n");

	struct 	period_info pinfo;
	periodic_task_init(&pinfo, 1000000000);
	printf("Initialized the periodic thread\n");

    char temp_data_bytes[sizeof(float)];
    float temp;

    char * states_fifo = "states_fifo";  // Not sure if this should be hardcoded
	int _states_fifo = open("states_fifo", O_RDONLY);
	if (_states_fifo < 0)
	{
		printf("Failed to open States FIFO. Exiting.\n");
		printf("%i\n", errno);
		exit(-1);
	}

	printf("Start of while loop control ops.\n");

	while(1)
	{
		printf("In control loop\n");
		if (read(_states_fifo, temp_data_bytes, sizeof(float)) < 0)
		{
			printf("Failed to read from fifo. Exiting.");
			exit(-1);
		}

		memcpy(&temp, temp_data_bytes, sizeof(float));

		//Test to read data from sensors:
		printf("Temperature (C): %f\n", temp);
		wait_rest_of_period(&pinfo);
	}
}


