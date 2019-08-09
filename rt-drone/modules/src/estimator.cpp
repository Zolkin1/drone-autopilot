/*
Reads the barometer data continuously in a background thread.
Will read it into a shared barometer object so we dont need to mess with pipe and buffers rn.
Should move to a queue system - prob write a wrapper for pipes or something like that. 
*/
#include "estimator.h"

void *estimator_thread(void *data)
{
    printf("in estimator");
    struct  period_info pinfo;
    periodic_task_init(&pinfo, LOOP_PERIOD);


    MS5611 barometer;
    barometer.initialize();
    printf("Baro initialzed\n");

    char temp_data_bytes[sizeof(float)];
    char pressure_data_bytes[sizeof(float)];	
    float temp;

    auto ptr = std::unique_ptr <InertialSensor>{ new MPU9250() };
    AHRS ahrs(move(ptr));
    ahrs.setGyroOffset();

    float roll;
    float pitch;
    float yaw;
    float thrust;

    float ax, ay, az;

    //struct state_struct estimated_states;
    float states[4];

    float dt = 1/LOOP_PERIOD;

    int _states_fifo = open(ESTIMATED_FIFO, O_WRONLY);
    if (_states_fifo < 0)
    {
        printf("Failed to open States FIFO. Exiting.");     
        printf("%i\n", errno);
        exit(-1);
    }

    printf("start of while loop estimator. \n");
	while(1)
	{
        printf("in while loop\n");

        //Use AHRS algo to update pos/orientation with IMU
        ahrs.updateIMU(dt);
        ahrs.getEuler(&roll, &pitch, &yaw);

        states[0] = roll;
        states[1] = pitch;
        states[2] = yaw;

        //RN get thrust just from IMU
        ptr->read_accelerometer(&ax, &ay, &az);
        //thrust = az;
        states[3] = az;

		/*barometer.refreshPressure();
        usleep(10000); // Waiting for pressure data ready
        barometer.readPressure();

        barometer.refreshTemperature();
        usleep(10000); // Waiting for temperature data ready
        barometer.readTemperature();

        barometer.calculatePressureAndTemperature();

        temp = barometer.getTemperature();
        memcpy(temp_data_bytes, &temp, sizeof(temp));*/



        if (write(_states_fifo, states, sizeof(state_struct)) < 0)
        {
            printf("Failed to write to states FIFO. Exiting.");
            exit(-1);
        }


        wait_rest_of_period(&pinfo);
	}
        return NULL;
}