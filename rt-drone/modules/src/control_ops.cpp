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

#include "control_ops.h"

void *control_ops_thread(void *data)
{
	printf("in control_ops\n");

	struct 	period_info pinfo;
	periodic_task_init(&pinfo, 1000000000);
	printf("Initialized the periodic thread\n");

    char temp_data_bytes[sizeof(float)];
    float temp;

    struct state_struct states_estimated;
    struct state_struct states_commanded;

	int _states_estimated_fifo = open_fifo(ESTIMATED_FIFO, O_RDONLY);
	int _states_commanded_fifo = open_fifo(COMMANDED_FIFO, O_RDONLY); //need to implement the communication thread first

	int control_mode;

	printf("Start of while loop control ops.\n");

	while(1)
	{
		switch (control_mode)
		{
			case CALIBRATION_MODE:
				read_fifo_states(_states_estimated_fifo, states_estimated);
				break;

			case TELEOPERATED_MODE:
				read_fifo_states(_states_estimated_fifo, states_estimated);
				read_fifo_states(_states_commanded_fifo, states_commanded);

				control_roll();
				control_pitch();
				control_yaw();
				control_throttle();

				break;

			case AUTONOMOUS_MODE:
				break;

			case EMERGENCY_MODE:
				break;
		}

		printf("In control loop\n");
		
		wait_rest_of_period(&pinfo);
	}
}

int read_fifo_states(int fifo, struct state_struct &states)
{
	char temp_bytes[sizeof(struct state_struct)];

	if(read(fifo, temp_bytes, sizeof(struct state_struct)) < 0)
	{
		printf("Failed to read fifo.\n");
		printf("%i\n", errno);
		return errno;
	}
	memcpy(&states, temp_bytes, sizeof(struct state_struct));
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