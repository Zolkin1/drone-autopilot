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

// Need to move fifo reads into c style arrays

#include "control_ops.h"

int read_fifo_float(int fifo, float * out);

void *control_ops_thread(void *data)
{
	//signal(SIGINT, catcher_controls);
	printf("in control_ops\n");

	//using namespace controls;

	quadRotorController controller;


	struct 	period_info pinfo;
	periodic_task_init(&pinfo, LOOP_PERIOD);
	printf("Initialized the periodic thread\n");

    char temp_data_bytes[sizeof(float)];
    float temp;

    float states_estimated [4];
    float states_commanded [4];

    //struct state_struct states_estimated;
    //struct state_struct states_commanded;

	int _states_estimated_fifo = open_fifo(ESTIMATED_FIFO, O_RDONLY);
	int _states_commanded_fifo = open_fifo(COMMANDED_FIFO, O_RDONLY);
	//int _mode_fifo = open_fifo(MODE_FIFO, O_RDONLY);

	int control_mode = TELEOPERATED_MODE;


	printf("Start of while loop control ops.\n");

	while (1)
	{
		char temp_bytes[sizeof(uint8_t)];
		/*if (read(_mode_fifo, temp_bytes, sizeof(int)) < 0)
		{
			printf("Failed to read fifo.\n");
			printf("%i\n", errno);
		}

		memcpy(&control_mode, temp_bytes, sizeof(int));*/

		switch (control_mode)
		{
			printf("In control ops loop");
			case CALIBRATION_MODE:
				//Calibrate all sensors
				read_fifo_states_float(_states_estimated_fifo, states_estimated);

				//Turn on/check/calibrate all motors

				break;

			case TELEOPERATED_MODE:
				printf("Reading from estimated");
				read_fifo_states_float(_states_estimated_fifo, states_estimated);
				printf("Reading from commanded states");
				read_fifo_states_float(_states_commanded_fifo, states_commanded);

				controller.control_to_state(states_estimated, states_commanded);
				read_fifo_states_float(_states_estimated_fifo, states_estimated);

				break;

			case AUTONOMOUS_MODE:
				read_fifo_states_float(_states_estimated_fifo, states_estimated);
				read_fifo_states_float(_states_commanded_fifo, states_commanded);

				//controller.control_to_state_velocity(states_estimated, states_commanded);

				break;

			case EMERGENCY_MODE:
				break;

			default:
				printf("Not a possible mode!");
				assert (false);
		}

		printf("In control loop\n");
		
		wait_rest_of_period(&pinfo);
	}
}

int read_fifo_states_float(int fifo, float * out)
{
    char temp_bytes[(sizeof(out)/sizeof(float))];
    if(read(fifo, temp_bytes, sizeof(out)/sizeof(float)) < 0)
    {
	    printf("Failed to read fifo");
	    printf("%i\n", errno);
	    return errno;
    }
    memcpy(out, temp_bytes, sizeof(temp_bytes));
}

//Can probably implement this as a template
int read_fifo_states(int fifo, uint8_t * out)
{
	char temp_bytes[sizeof(out)/sizeof(uint8_t)];

	if(read(fifo, temp_bytes, sizeof(out)/sizeof(uint8_t)) < 0)
	{
		printf("Failed to read fifo.\n");
		printf("%i\n", errno);
		return errno;
	}
	memcpy(out, temp_bytes, sizeof(temp_bytes));
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
