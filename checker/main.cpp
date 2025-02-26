#include <iostream>
#include "request.h"
#include "ioctl.h"

int main()
{
  if (!Ioctl::Init()) {
    return 1;
  }

  auto rdtscRes = Req::RdtscCheck();
  std::cout << std::get<0>(rdtscRes) << ' ' << std::get<1>(rdtscRes) << '\n';

  Ioctl::Terminate();
}