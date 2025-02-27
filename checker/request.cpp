#include "request.h"

REQ_TYPE Req::ReqWrapper(const DWORD type) {
  DWORD out = TRUE;
  if (!Ioctl::Request(
    type,
    NULL,
    0,
    &out,
    sizeof(DWORD)
  )) {
    LogConsole("Failed to send request.\n");
    return REQ_TYPE(false, false);
  }
  return REQ_TYPE(true, out != FALSE);
}

REQ_TYPE Req::RdtscCheck() {
  return ReqWrapper(GloVar::Ioctl::IOCTL_HYDCT_RDTSC_CHECK);
}

REQ_TYPE Req::GarbageWriteToMsr() {
  return ReqWrapper(GloVar::Ioctl::IOCTL_HYDCT_GARBAGE_WRITE_TO_MSR);
}

PVOID g_Checks[DETECTION_VECTOR_COUNT] = {
  Req::RdtscCheck,
  Req::GarbageWriteToMsr
};