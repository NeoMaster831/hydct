#include "d_rdtsc.h"

BOOL DctRdtscCheck() {

  const UINT64 REFLECT_COUNT = 60;
  const UINT64 TRIM_COUNT = 15;

  PriorityQueue* pq = PriorityQueueCreate(REFLECT_COUNT + TRIM_COUNT);
  UINT64 sum = 0;

  for (UINT64 i = 0; i < REFLECT_COUNT + TRIM_COUNT; i++) {
    
    UNUSED_PARAMETER(i);

    UINT64 clockStart = __rdtsc();

    int cpuInfo[4] = { 0 };
    UNUSED_PARAMETER(cpuInfo);
    __cpuidex(cpuInfo, 0, 0);
    
    UINT64 clockEnd = __rdtsc();

    PriorityQueuePush(pq, clockEnd - clockStart);
  }

  for (UINT64 i = 0; i < TRIM_COUNT; i++) {

    UNUSED_PARAMETER(i);
    
    /*
    UINT64 value = 0;
    PriorityQueueTop(pq, &value);
    HD_LOG_INFO("rdtsc (trim): %llu\n", value);
    */

    PriorityQueuePop(pq);
  }

  while (!PriorityQueueIsEmpty(pq)) {
    UINT64 value = 0;
    PriorityQueueTop(pq, &value);
    //HD_LOG_INFO("rdtsc: %llu\n", value);
    sum += value;
    PriorityQueuePop(pq);
  }

  UINT64 avg = sum / REFLECT_COUNT;

  HD_LOG_INFO("rdtsc avg: %llu\n", avg);

  if (avg > RDTSC_CHK_I7_12700H_DEADLINE)
    return TRUE;

  return FALSE;
}