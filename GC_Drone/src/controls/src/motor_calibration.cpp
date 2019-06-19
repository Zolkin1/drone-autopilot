#include <unistd.h>
#include "header-files/PWM.h"
#include "header-files/RCOutput_Navio.h"
#include "header-files/RCOutput_Navio2.h"
#include "header-files/Util.h"
#include <unistd.h>
#include <memory>
#include <string>
#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"


#define SERVO_MIN 1000 /*mS*/ //0
#define SERVO_MAX 1500 /*mS*/ //1750

#define PWM_OUTPUT 0 //Specifies whhich hardware channel to use

std::string input;

void changeOutput(const std_msgs::String::ConstPtr& msg)
{
    input = msg->data;
}

using namespace Navio;

std::unique_ptr <RCOutput> get_rcout()
{
    auto ptr = std::unique_ptr <RCOutput>{ new RCOutput_Navio2() };
    return ptr;
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "controls2");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("changeOut", 100, changeOutput);

    ros::Rate loop_rate(10);
    printf("%s\n", "ros has been started");

    input = "low";

    auto pwm = get_rcout();
    
    if (check_apm()) {
        return 1;
    }

    if (getuid()) {
        fprintf(stderr, "Not root. Please launch like this: sudo %s\n", argv[0]);
    }


    if( !(pwm->initialize(PWM_OUTPUT)) ) {
        return 1;
    }
        
	pwm->set_frequency(PWM_OUTPUT, 50);

	if ( !(pwm->enable(PWM_OUTPUT)) ) {
	    return 1;
	}

    printf("Enter 'low' to send singal low, enter 'high' to send signal high. Default is high \n");

    while (ros::ok()) 
    {
        if (input == "low")
        {
            pwm->set_duty_cycle(PWM_OUTPUT, SERVO_MIN);    
        }
        else
        {
            pwm->set_duty_cycle(PWM_OUTPUT, SERVO_MAX);
        }

        ros::spinOnce();

        //May need to remove this if pwm output is not working properly
        //loop_rate.sleep();
    }

    return 0;
}
