/*
Reads the barometer data continuously in a background thread.
Will read it into a shared barometer object so we dont need to mess with pipe and buffers rn.
Should move to a queue system - prob write a wrapper for pipes or something like that. 
*/
#include "estimator.h"

using std::ofstream;

/*void catcher_estimator(int sig)
{
    fclose(debug_file);
    printf("Caught signal - estimator!\n");
    exit(-1);
}*/

void *estimator_thread(void *data)
{
    //signal(SIGINT, catcher_estimator);    
    printf("[ESTIMATOR THREAD]: in estimator\n");
    struct  period_info pinfo;
    periodic_task_init(&pinfo, LOOP_PERIOD);

    MS5611 barometer;
    barometer.initialize();
    printf("[ESTIMATOR THREAD]: Baro initialzed\n");

    char temp_data_bytes[sizeof(float)];
    char pressure_data_bytes[sizeof(float)];	
    float temp;

    auto ptr = std::unique_ptr <InertialSensor>{ new MPU9250() };
    AHRS ahrs(move(ptr));
    ahrs.setGyroOffset();

    
    //estimator_debug = fopen("test1.txt", "w");
    //ofstream debug_file;
    //debug_file.open("/home/pi/drone-autopilot/estimation_logs.txt"); //Make it log to a "data" folder. User might not be "pi"   

    //struct state_struct estimated_states;
    float states[4];

    float dt = 1/LOOP_PERIOD;

    int _states_fifo = open(ESTIMATED_FIFO, O_WRONLY);
    if (_states_fifo < 0)
    {
        printf("[ESTIMATOR THREAD]: Failed to open States FIFO. Exiting.\n");     
        printf("%i\n", errno);
        exit(-1);
    }

    printf("[ESTIMATOR THREAD]: start of while loop estimator. \n");
	while (1)
	{
        printf("[ESTIMATOR THREAD]: in while loop\n");
        printf("[ESTIMATOR THREAD]: making vars\n");
        //Use AHRS algo to update pos/orientation with IMU
        float roll;
        float pitch;
        float yaw;
        float thrust;
        float ax, ay, az;

        printf("[ESTIMATOR THREAD]: reading imu AHRS\n");
        ahrs.updateIMU(dt);
        ahrs.getEuler(&roll, &pitch, &yaw);

        states[0] = roll;
        states[1] = pitch;
        states[2] = yaw;

        printf("[ESTIMATOR THREAD]: reading the accelerometer\n");
        //Rn get thrust just from IMU
        auto imu2 = std::unique_ptr <InertialSensor>{new MPU9250()};
        imu2->read_accelerometer(&ax, &ay, &az);
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

	
        printf("[ESTIMATOR THREAD]: just about to write to FIFO\n");
        if (write(_states_fifo, states, sizeof(states)) < 0)
        {
            printf("[ESTIMATOR THREAD]: Failed to write to states FIFO. Exiting.\n");
            exit(-1);
        }

        printf("[ESTIMATOR THREAD]: just about to log to file\n");
        // Log data to the debug file
        fprintf(estimator_debug, "%f %f %f %f %f %f\n", roll, pitch, yaw, ax, ay, az );
        //debug_file << roll << " " << pitch << " " << yaw << " " << ax << " " << ay << " " << az << "\n"; 
        wait_rest_of_period(&pinfo);
	}
        return NULL;
}
