#include "request.h"

std::tuple<bool, bool> Req::RdtscCheck() {
  DWORD out = TRUE;

  if (!Ioctl::Request(
    GloVar::Ioctl::IOCTL_HYDCT_RDTSC_CHECK,
    NULL,
    0,
    &out,
    sizeof(DWORD)
  )) {
    LogConsole("Failed to send request.\n");
    return std::tuple<bool, bool>(false, false);
  }

  LogConsole("Request sent.\n");
  return std::tuple<bool, bool>(true, out != FALSE);
}