// NEED TO WRITE MAKEFILE TO COMPILE PROPERLY
 
#include <limits.h>
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "thread_helpers.h"
#include "MS5611.h"
#include "control_ops.h"
#include "estimator.h"
 
pthread_attr_t initRTThread(int sched_policy, int sched_prior)
{
    struct sched_param param;
    pthread_attr_t attr;
    int ret;

    /* Initialize pthread attributes (default values) */
    ret = pthread_attr_init(&attr);
    if (ret) {
            printf("init pthread attributes failed\n");
            goto out;
    }

    /* Set a specific stack size  */
    ret = pthread_attr_setstacksize(&attr, PTHREAD_STACK_MIN);
    if (ret) {
        printf("pthread setstacksize failed\n");
        goto out;
    }

    /* Set scheduler policy and priority of pthread */
    ret = pthread_attr_setschedpolicy(&attr, sched_policy);
    if (ret) {
            printf("pthread setschedpolicy failed\n");
            goto out;
    }

    param.sched_priority = sched_prior;
    ret = pthread_attr_setschedparam(&attr, &param);
    if (ret) {
            printf("pthread setschedparam failed\n");
            goto out;
    }

    /* Use scheduling parameters of attr */
    ret = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    if (ret) {
            printf("pthread setinheritsched failed\n");
            goto out;
    }

    return attr;

out:
    exit(1);
}

int main(int argc, char* argv[])
{
 	printf("in main \n");

    /* Lock memory */
    // This should lock memory for entire process, not just one thread
    /* Right now, need sudo privliges for this on Navio2*/
    if(mlockall(MCL_CURRENT|MCL_FUTURE) == -1) {
            printf("mlockall failed: %m\n");
            exit(-2);
    }

    //char * states_fifo = "/tmp/states_fifo"; 
    mkfifo("/tmp/states_fifo", 0666);

    pthread_t control_ops;
    pthread_t estimator;

    pthread_attr_t attr_control_ops = initRTThread(SCHED_FIFO, 80);
    pthread_attr_t attr_estimator = initRTThread(SCHED_FIFO, 70);

    int ret = pthread_create(&estimator, &attr_estimator, estimator_thread, NULL); //Change NULL to a pointer to the barometer object
    if (ret) 
    {
            printf("create pthread barometer failed\n");
            goto out;
    }

    ret = pthread_create(&control_ops, &attr_control_ops, control_ops_thread, NULL); //Pass the sensor struct in here instead of NULL
    if (ret) 
    {
            printf("create pthread control_ops failed\n");
            goto out;
    }

    return ret;

out:    
    return ret;
}
