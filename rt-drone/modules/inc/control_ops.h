#pragma once

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <cerrno>
#include <cassert>
#include <csignal>

#include "thread_helpers.h"
#include "MS5611.h"
#include "quad_rotor_controller.h"
#include "constants.h"

static const int CALIBRATION_MODE = 0;
static const int TELEOPERATED_MODE = 1;
static const int AUTONOMOUS_MODE = 2;
static const int EMERGENCY_MODE = 3;

int read_fifo_states(int fifo, struct state_struct &states);
int open_fifo(char* fifo, int status);
void *control_ops_thread(void *data);
void catcher_controls(int sig);
