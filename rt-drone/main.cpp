/*
May want to move all pipe data types to c style arrays. Also maybe protobufs in the future?
*/
 
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
#include <cerrno>
#include <csignal>

#include "thread_helpers.h"
#include "MS5611.h"
#include "control_ops.h"
#include "estimator.h"
#include "constants.h"
#include "communication.h"
 
void catcher_function(int sig)
{
    printf("Caught signal!\n");
    exit(-1);
}

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
    signal(SIGINT, catcher_function);
 	printf("in main \n");

    /* Lock memory */
    // This should lock memory for entire process, not just one thread
    /* Right now, need sudo privliges for this on Navio2*/
    if(mlockall(MCL_CURRENT|MCL_FUTURE) == -1) {
            printf("mlockall failed: %m\n");
            exit(-2);
    }

    //Only run this if you have yet to make the fifo
/*    if (mkfifo(ESTIMATED_FIFO, 0666) < 0)
    {
        printf("Failed to make FIFO. \n");
        printf("%i\n", errno);
        return -1;
    }

    if (mkfifo(COMMANDED_FIFO, 0666) < 0)
    {
        printf("Failed to make FIFO. \n");
        printf("%i\n", errno);
        return -1;
    }

    if (mkfifo(MODE_FIFO, 0666) < 0)
    {
        printf("Failed to make FIFO. \n");
        printf("%i\n", errno);
        return -1;
    }
*/
    pthread_t control_ops;
    pthread_t estimator;
    pthread_t communication;

    pthread_attr_t attr_control_ops = initRTThread(SCHED_FIFO, 80);
    pthread_attr_t attr_estimator = initRTThread(SCHED_FIFO, 70);
    pthread_attr_t attr_communication = initRTThread(SCHED_FIFO, 60); //E stop will need to be an interrupt

    int ret = pthread_create(&estimator, &attr_estimator, estimator_thread, NULL);
    if (ret) 
    {
            printf("create pthread barometer failed\n");
            goto out;
    }

    ret = pthread_create(&control_ops, &attr_control_ops, control_ops_thread, NULL);
    if (ret) 
    {
            printf("create pthread control_ops failed\n");
            goto out;
    }

    ret = pthread_create(&communication, &attr_communication, communication_thread, NULL);
    if (ret) 
    {
            printf("create pthread control_ops failed\n");
            goto out;
    }

    ret = pthread_join(control_ops, NULL);
    if (ret)
    {
        printf("Failed to join thread. \n");
    }

    ret = pthread_join(estimator, NULL);
    if (ret)
    {
        printf("Failed to join thread. \n");
    }

    ret = pthread_join(communication, NULL);
    if (ret) 
    {
        printf("Failed to join thread. \n");
    }

    return ret;

out:    
    return ret;
}
