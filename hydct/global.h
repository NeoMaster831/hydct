#pragma once

#include "utils.h"

typedef unsigned int BOOL;

#define IOCTL_HYDCT_RDTSC_CHECK \
  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)