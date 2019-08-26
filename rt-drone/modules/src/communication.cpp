/*
Handle UDP and RC IO in thread. The commanded states should just output the mux of the two.
Probably make estop an interrupt into the control thread. E stop comes from SCP over UDP.
*/

/*
In the begginnning this will just be a simple RC input node running at the rate of the control loop.
*/

#include "communication.h"
using std::ofstream;

void *communication_thread(void *data)
{
	printf("[COMMS THREAD]: in communication \n");
    struct  period_info pinfo;
    periodic_task_init(&pinfo, LOOP_PERIOD);


	RCInput_Navio2 rcin;
	//rcin.initialize();
	//uint8_t channel_in[6];
	float channel_in[4];

	int _states_commanded_fifo = open_fifo_status(COMMANDED_FIFO, O_WRONLY);
	if (_states_commanded_fifo < 0)
    {
        printf("[COMMS THREAD]: Failed to open States FIFO. Exiting.\n");     
        printf("%i\n", errno);
        exit(-1);
    }

    FILE * debug_tele_inputs = fopen("tele_inputs", "w");
    //debug_tele_inputs.open("home/pi/data/rc_inputs.txt");

	while(1)
	{
		for (int i = 0; i < 4; i++) //6 channel remote, but only reading 4
		{
			printf("[COMMS THREAD]: Reading value from rcin\n");
			//channel_in[i] = rcin.read(i);
			channel_in[i] = 1;
		}

		printf("[COMMS THREAD]: Writing to file\n");
		fprintf(debug_tele_inputs, "%f, %f, %f, %f\n", channel_in[0], channel_in[1], channel_in[2], channel_in[3]);	
		//debug_tele_inputs << "RC Inputs: " << channel_in[0] << " " << channel_in[1] << " " << channel_in[2] << " " << channel_in[3] << " " << channel_in[4] << " " << channel_in[5] << "\n";

		printf("[COMMS THREAD]: Writing to fifo\n");
		if (write(_states_commanded_fifo, channel_in, sizeof(channel_in)) < 0)
        {
            printf("[COMMS THREAD]: Failed to write to states FIFO. Exiting.\n");
            exit(-1);
        }

        wait_rest_of_period(&pinfo);
	}
}

int open_fifo_status(char* fifo, int status)
{
	int fd = open(fifo, status);

	if (fd < 0)
	{
		printf("[COMMS THREAD]: Failed to open States FIFO. Exiting.\n");
		printf("%i\n", errno);
		return(errno);
	}

	return fd;
}
