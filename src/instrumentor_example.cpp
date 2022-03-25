#include "Instrumentor.h"
#include <iostream>

void Function1() {
  PROFILE_FUNCTION();
  for (int i = 0; i < 2000; ++i) {
    std::cout << __FUNCTION__ << ": " << i << std::endl;
  }
}

void Function1(int a) {
  PROFILE_FUNCTION();
  for (int i = 0; i < 2000; ++i) {
    std::cout << __FUNCTION__ << ": " << i * a << std::endl;
  }
}

void Run_Benchmarks() {

  PROFILE_FUNCTION();
  std::cout << "Running benchmarks ... \n";
  Function1();
  Function1(2);
}

int main() {
  Instrumentor::Get().BeginSession("Profile");
  Run_Benchmarks();
  Instrumentor::Get().EndSession();
  return 0;
}