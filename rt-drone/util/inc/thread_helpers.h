#pragma once

#include <limits.h>
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define ESTIMATED_FIFO "estimated_states_fifo"
#define COMMANDED_FIFO "commanded_states_fifo"
#define MODE_FIFO "mode_fifo"

struct period_info 
{
    struct timespec next_period;
    long period_ns;
};

struct state_struct
{
	float thrust;
	float roll;
	float pitch;
	float yaw;
};

void inc_period(struct period_info *pinfo);
void periodic_task_init(struct period_info *pinfo, int period);
void wait_rest_of_period(struct period_info *pinfo);
