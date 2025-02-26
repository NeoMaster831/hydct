#pragma once

#include "ioctl.h"
#include <tuple>

namespace Req {

  /*
   * @brief rdtsc check
   * @return `std::tuple<bool, bool>`: first is `TRUE` if request was successful, second is `TRUE` if hypervisor detected
   */
  std::tuple<bool, bool> RdtscCheck();
}