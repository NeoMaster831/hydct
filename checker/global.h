#pragma once

#include <Windows.h>

#include "utils.h"

#define CTL_CODE( DeviceType, Function, Method, Access ) (                 \
    ((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) \
)

namespace GloVar {
  namespace Ioctl {

    const DWORD IOCTL_HYDCT_RDTSC_CHECK = \
      CTL_CODE(0x22, 0x800, 0x0, 0x0);

    extern HANDLE hDevice;
  }
}