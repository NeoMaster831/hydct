#pragma once

#include "global.h"

#include "dspq.h"

/*
 * @brief rdtsc check
 * @return `TRUE` if hypervisor detected, `FALSE` otherwise
 */
BOOL DctRdtscCheck();

#define RDTSC_CHK_I7_12700H_DEADLINE 2618