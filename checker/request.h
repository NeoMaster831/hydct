#pragma once

#include "ioctl.h"
#include <tuple>

#define REQ_TYPE std::tuple<bool, bool>

namespace Req {

  REQ_TYPE ReqWrapper(const DWORD type);

  /*
   * @brief rdtsc check
   * @return `REQ_TYPE`: first is `TRUE` if request was successful, second is `TRUE` if hypervisor detected
   */
  REQ_TYPE RdtscCheck();
  
  /*
   * @brief garbage write to MSR check
   * @return `REQ_TYPE`: first is `TRUE` if request was successful, second is `TRUE` if hypervisor detected
   */
  REQ_TYPE GarbageWriteToMsr();
  
}

extern PVOID g_Checks[DETECTION_VECTOR_COUNT];