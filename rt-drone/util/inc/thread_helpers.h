#pragma once

#include <limits.h>
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

struct period_info 
{
        struct timespec next_period;
        long period_ns;
};

void inc_period(struct period_info *pinfo);
void periodic_task_init(struct period_info *pinfo, int period);
void wait_rest_of_period(struct period_info *pinfo);
