#include <unistd.h>
#include "PWM.h"
#include "RCOutput_Navio.h"
#include "RCOutput_Navio2.h"
#include "Util.h"
#include <unistd.h>
#include <memory>
#include <string>
#include <iostream>

#define SERVO_MIN 1250 /*mS*/
#define SERVO_MAX 1750 /*mS*/

#define PWM_OUTPUT 0 //Specifies whhich hardware channel to use


using namespace Navio;

std::unique_ptr <RCOutput> get_rcout()
{
    auto ptr = std::unique_ptr <RCOutput>{ new RCOutput_Navio2() };
    return ptr;
}

int main(int argc, char *argv[])
{

    std::string input = "low";

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

    while (true) 
    {
        if (input == "low")
        {
            pwm->set_duty_cycle(PWM_OUTPUT, SERVO_MIN);    
        }
        else
        {
            pwm->set_duty_cycle(PWM_OUTPUT, SERVO_MAX);
        }
        std::cin >> input;   
    }

    return 0;
}