/*
This controller should be at the highest level, then delegate out sub tasks to other controllers if necessary.
This controller will have subcontrollers that control:
	Roll
	Pitch
	Yaw
	Height
	Body Velocity

Body velocity should be used in teleop mode and possibly during autonomous navigation.
Roll, Pitch and Yaw will be used for stability. Height should be a basic position controller.

After all of these controllers have been applied, the result will need to muxed into an ouput for the bldc motor.
The motor takes a PWM command that dictates speed.

For the motor: 1000 ms is off, and 2000 ms is maximum power. The PWM signal is being transmitted at 50 hz. Low level speed/torque
control should be happening in the firmware on the ESCs, but if this is not giving us desired tracking then we can look into using
an FPGA with a custom controller (like sensorless FOC). The means that there cannot be any speed controller (we also don't have encoders
or the ability to read back EMF from the ESCs).

This node will not have a state machine for any given control type - the drone always needs to be applying control signals to the motor to stay
stable. In the case where you want the drone to stay in the same location, send the same desired position, and the drone
will attempt to maintain its current state. In the case of staying on the ground, there will be a special flag, and when
that flag is thrown then the drone is not apply power to motors (this could be seen as a state in a state machine, but if so
there are only two states: control and do nothing). It is possible that in the future we decide to change the architecture
to implement a state machine at this level, but for now this node will only do math and apply a control signal.

Addition: in the case of fixed wing flight and quadrotoflight, that should probably be modeled as a state machine (todo later)


This controller will take a desired state msg (needs to be created as of 6/6/2019).
*/


/*
Recieving messages:
	est_state
	des_state

Publishing messages:
	motor_commands
*/

#include "top_level_controller.h"


void updateState (const estimator::quad_rotor_states::ConstPtr& msg)
{
	mainController.setDesiredState(msg);
}

void changeTarget (const estimator::quad_rotor_states::ConstPtr& msg)
{
	mainController.setEstimatedState(msg);
}

int main(int argc, char **argv)
{

	//Init all the ros stuff - this node will be a publish and subscriber
	ros::init(argc, argv, "top_level_controller");
	ros::NodeHandle n;

	//Subscribe to the topics that publish a message: estimator::quad_rotor_states
	ros::Subscriber est_state_sub = n.subscribe("est_state", 100, updateState);
	ros::Subscriber des_state_sub = n.subscribe("des_state", 100, changeTarget);

	ros::Publisher motor_comm_pub = n.advertise<estimator::motor_commands>("motor_commands", 1000);
    ros::Rate loop_rate(20);

    using namespace controller;

    K << 1, 1, 1, 1, 1, 1; //Change the dimensions and numbers to actual gain

    mainController.setK(K);

    while(ros::ok())
    {
    	/*
    	Perform controls math.
    	Return 4 duty cycles.
    	*/
    	controlInputs = mainController.getInputs();
    	speeds = mapInputsToSpeed(controlInputs, 1.0, 1.0, 0.1); //Seems like this should be a pass by refrence with no return
    	dutyCycles = speedToDutyCycles(speeds); //Seems like this should be a pass by refrence with no return


    	//Publish the duty cycles
    	motor_comm_pub.publish(dutyCycles);
    	ros::spinOnce();

    	loop_rate.sleep();
    }
    return 0;
}

Eigen::Vector4f mapInputsToSpeed(Eigen::Vector4f controlInputs, float b, float l, float d)
{
	/*
	Solve these equations:
	b is thrust factor
	l is distance from center of the drone to the rotor
	d is drag factor
	w is the speed of a rotor	

	ft = b(w1^2 + w2^2 + w3^2 w4^2)
	tx = bl(w3^2 - w1^2)
	ty = bl(w4^2 - -w2^2)
	tz = d(w2^2 + w4^2 - w1^2 - w3^2)
	
	return vector of w
	*/

	Eigen::Matrix4f A;
	A << b, b, b, b,
		-b*l, 0.0, b*l, 0.0,
		0.0, -b*l, 0.0, b*l,
		-d, d, -d, d;
	
	Eigen::Matrix4f invA = A.inverse();

	return invA.lu().solve(controlInputs);  
}

estimator::motor_commands speedToDutyCycles(Eigen::Vector4f speeds)
{
	estimator::motor_commands motorComms;
	return motorComms;
}