#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "thread_helpers.h"
#include "MS5611.h"

void *estimator_thread(void *data);
