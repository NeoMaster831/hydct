#pragma once

#include <stdio.h>
#include <iostream>

#ifdef _DEBUG

#define LogConsole(Format, ...) fprintf(stdout, "Debug: " Format, __VA_ARGS__)

#else

#define LogConsole(Format, ...)

#endif