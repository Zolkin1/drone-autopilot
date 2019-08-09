#pragma once

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <cerrno>
#include <unistd.h>

#include "RCInput_Navio2.h"
#include "RCInput_Navio.h"
#include "Util.h"
#include "constants.h"
#include "thread_helpers.h"

#include <memory>
#include <array>

void* communication_thread(void *data);
int open_fifo_status(char* fifo, int status); // need to put this in thread_helpers