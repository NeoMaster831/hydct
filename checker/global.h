#pragma once

#include <Windows.h>

#include "utils.h"

#define CTL_CODE( DeviceType, Function, Method, Access ) (                 \
    ((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) \
)

#define DETECTION_VECTOR_COUNT 2

namespace GloVar {
  namespace Ioctl {

    const DWORD IOCTL_HYDCT_RDTSC_CHECK = \
      CTL_CODE(0x22, 0x800, 0x0, 0x0);

    const DWORD IOCTL_HYDCT_GARBAGE_WRITE_TO_MSR = \
      CTL_CODE(0x22, 0x801, 0x0, 0x0);

    extern HANDLE hDevice;
  }
}