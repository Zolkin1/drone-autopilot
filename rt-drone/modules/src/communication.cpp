/*
Handle UDP and RC IO in thread. The commanded states should just output the mux of the two.
Probably make estop an interrupt into the control thread. E stop comes from SCP over UDP.
*/

/*
In the begginnning this will just be a simple RC input node running at the rate of the control loop.
*/

#include "communication.h"

void *communication_thread(void *data)
{
	printf("in communication");
    struct  period_info pinfo;
    periodic_task_init(&pinfo, LOOP_PERIOD);


	RCInput_Navio2 rcin;
	rcin.initialize();
	int channel_in[6];

	int _states_commanded_fifo = open_fifo(COMMANDED_FIFO, O_WRONLY);
	if (_states_commanded_fifo < 0)
    {
        printf("Failed to open States FIFO. Exiting.");     
        printf("%i\n", errno);
        exit(-1);
    }

	while(1)
	{
		for (int i = 0; i < 6; i++) //6 channel remote
		{
			channel_in[i] = rcin.read(i);
		}

		if (write(_states_commanded_fifo, channel_in, sizeof(channel_in)) < 0)
        {
            printf("Failed to write to states FIFO. Exiting.");
            exit(-1);
        }

        wait_rest_of_period(&pinfo);
	}
}

int open_fifo(char* fifo, int status)
{
	int fd = open(fifo, status);

	if (fd < 0)
	{
		printf("Failed to open States FIFO. Exiting.\n");
		printf("%i\n", errno);
		return(errno);
	}

	return fd;
}