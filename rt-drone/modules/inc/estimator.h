#pragma once
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <memory>
#include <cerrno>
#include <fstream>
#include <csignal>

#include "thread_helpers.h"
#include "MS5611.h"
#include "constants.h"
#include "MPU9250.h"
#include "InertialSensor.h"
#include "AHRS.h"

void *estimator_thread(void *data);
