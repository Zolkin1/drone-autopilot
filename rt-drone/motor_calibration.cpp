#include <unistd.h>
#include <iostream>
#include <memory>

#include "constants.h"
#include "PWM.h"
#include "RCOutput_Navio.h"
#include "RCOutput_Navio2.h"
#include "Util.h"

#define PWM_OUTPUT 0 //Plug motor into pwm out 0

int main()
{
	auto pwm = std::unique_ptr <RCOutput>{ new RCOutput_Navio2() };

	if (getuid())
	{
		printf("Run as root! Exiting. \n");
		return -1;
	}

	if (!(pwm->initialize(PWM_OUTPUT)))
	{
		return 1;
	}

	pwm->set_frequency(PWM_OUTPUT, 50);

	if ( !(pwm->enable(PWM_OUTPUT)) ) 
	{
	    return 1;
	}

	printf("Enter 1 to go high. Any other number to go low. Defualt is high. Plug into pwm 0. \n");
	
	int flag = 1;
	while(true)
	{
		if (flag == 1)
		{
			pwm->set_duty_cycle(PWM_OUTPUT, MAX_DUTY_CYCLE);    	

		}
		else
		{
			pwm->set_duty_cycle(PWM_OUTPUT, MIN_DUTY_CYCLE);    	
		}
		std::cin >> flag; //Wait until we get input
	}
}