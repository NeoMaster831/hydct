#include <iostream>
#include "request.h"
#include "ioctl.h"

// Terminal color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main()
{

  std::cout << BOLD << CYAN;
  std::cout << "  _    _            _      _    \n";
  std::cout << " | |  | |          | |    | |   \n";
  std::cout << " | |__| |_   _  ___| | ___| |_  \n";
  std::cout << " |  __  | | | |/ __  |/ __| __| \n";
  std::cout << " | |  | | |_| | (__| | (__| |_  \n";
  std::cout << " |_|  |_|\\__, |\\_____|\\___|\\__| \n";
  std::cout << "          __/ |                 \n";
  std::cout << "         |___/                  \n";
  std::cout << RESET << "\n";

  if (!Ioctl::Init()) {
    std::cout << BOLD << RED << "[ERROR] Failed to initialize IOCTL" << RESET << "\n";
    return 1;
  }

  std::cout << YELLOW << "Running " << DETECTION_VECTOR_COUNT << " detection methods..." << RESET << "\n";
  std::cout << BLUE << "----------------------------------------" << RESET << "\n";

  for (auto i = 0; i < DETECTION_VECTOR_COUNT; i++) {
    auto res = ((REQ_TYPE(*)())g_Checks[i])();
    bool success = std::get<0>(res);
    bool detected = std::get<1>(res);

    std::cout << BOLD << "[" << i << "] " << RESET;

    std::cout << "Request Status: ";
    if (success) {
      std::cout << GREEN << "Success" << RESET;
    }
    else {
      std::cout << RED << "Failed" << RESET;
    }

    std::cout << " | ";

    std::cout << "Hypervisor Detected: ";
    if (detected) {
      std::cout << RED << BOLD << "Yes" << RESET;
    }
    else {
      std::cout << GREEN << "No" << RESET;
    }

    std::cout << '\n';
  }

  std::cout << BLUE << "----------------------------------------" << RESET << "\n";
  std::cout << MAGENTA << "Detection complete!" << RESET << "\n\n";

  Ioctl::Terminate();
  return 0;
}