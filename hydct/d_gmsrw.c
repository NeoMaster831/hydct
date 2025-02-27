#include "d_gmsrw.h"

BOOL DctGarbageWriteToMsr() {

  BOOL readTest = FALSE;
  BOOL writeTest = FALSE;

  // First, test read action
  __try {
    unsigned long long returnValue = __readmsr(0xdeadbeef);
    UNUSED_PARAMETER(returnValue);
  }
  __except (EXCEPTION_EXECUTE_HANDLER) {
    readTest = TRUE;
  }

  HD_LOG_INFO("readTest: %u", readTest);

  // Second, test write action
  __try {
    __writemsr(0xdeadbeef, 0xabcdef6974);
  }
  __except (EXCEPTION_EXECUTE_HANDLER) {
    writeTest = TRUE;
  }

  HD_LOG_INFO("writeTest: %u", writeTest);

  if (readTest && writeTest)
    return FALSE;

  // Hypervisor is not correctly handling invalid MSR write, so hypervisor is detected
  return TRUE;

}