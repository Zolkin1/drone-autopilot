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


#include "control_ops.h"

struct period_info 
{
    struct timespec next_period;
    long period_ns;
};

static void inc_period(struct period_info *pinfo) 
{
        pinfo->next_period.tv_nsec += pinfo->period_ns;
 
        while (pinfo->next_period.tv_nsec >= 1000000000) 
        {
                /* timespec nsec overflow */
                pinfo->next_period.tv_sec++;
                pinfo->next_period.tv_nsec -= 1000000000;
        }
}
 
static void periodic_task_init(struct period_info *pinfo, int period)
{
        /* for simplicity, hardcoding a 1s period */
        pinfo->period_ns = period;
 
        clock_gettime(CLOCK_MONOTONIC, &(pinfo->next_period));
}
 
static void wait_rest_of_period(struct period_info *pinfo)
{
        inc_period(pinfo);
 
        /* for simplicity, ignoring possibilities of signal wakes */
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &pinfo->next_period, NULL);
}

void *control_ops_thread(void *data)
{
	printf("in control_ops\n");

	struct 	period_info pinfo;
	periodic_task_init(&pinfo, 100000000);

    char temp_data_bytes[sizeof(float)];
    float temp;

    //char * states_fifo = "/tmp/states_fifo";  // Not sure if this should be hardcoded
	int _states_fifo = open("/tmp/states_fifo", O_RDONLY);
	if (_states_fifo < 0)
	{
		printf("Failed to open States FIFO. Exiting.");
		exit(-1);
	}

	printf("Start of while loop control ops.\n");

	while(1)
	{
		printf("In estimator loop\n");
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


