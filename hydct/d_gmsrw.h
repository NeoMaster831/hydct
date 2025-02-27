#pragma once

#include "global.h"

#include <intrin.h>

/*
 * @brief Check hypervisor presentation with garbage write to MSR
 * @details check if bare-metal CORRECTLY injects GP exception on MSR write
 * @return `TRUE` if hypervisor detected, `FALSE` otherwise
 */
BOOL DctGarbageWriteToMsr();