#pragma once

#define LOOP_PERIOD 1000000000
static const int MAX_DUTY_CYCLE = 1500;
static const int MIN_DUTY_CYCLE = 1000;
static const int MAX_MOTOR_SPEED = 50; //No idea if this is the correct word

namespace files
{
}

static FILE* estimator_debug = fopen("test1.txt", "w");
static FILE* motor_debug = fopen("motors_logs.txt", "w");
static FILE* rpy_debug = fopen("rpy_logs.txt", "w");
