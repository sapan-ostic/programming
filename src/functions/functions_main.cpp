/**
 * @file functions_main.cpp
 * @author sapan agrawal
 * @brief Functions
 * 1. Prototyping and definition
 * 2. Default Parameters
 * 3. Function Overloading
 * 4. Scope of the function
 * 5. Function Pointers
 * 6. Optional Functions parameters
 *   a. inline
 *   b. constexpr
 *   c. noexcept
 *   d. extern & static
 */

#include "Instrumentor.h"
#include <iostream>
#include <vector>

// 1. Function Prototype/Declaration
// 2. Default parameters
void Print(int *list, const int size = 10);

// 3. Overloading Print() function
void Print(std::vector<int> &);

// Cannot differentiate functions alone with return type
// int Print(std::vector<int>&);

// 5. Function Pointers
int Add(const int &a, const int &b);
int (*operation_fn_ptr)(const int &a, const int &b) = Add;

// 6.a. Inline Functions
int SquareRegular(int val) { return val * val; }
inline int SquareInline(int val) { return val * val; }

void RunBenchmarks();

int main() {
  // initializing array with 0
  int samples[10]{0};
  printf("Printing array ... \n");
  Print(samples);

  std::vector<int> v_samples(10, 0);
  printf("Printing array ... \n");
  Print(v_samples);

  printf("functions pointer: 2+3 = %d\n", operation_fn_ptr(2, 3));

  RunBenchmarks();
  return 0;
}

// Function Definition
void Print(int *list, const int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << list[i];
  }
  std::cout << std::endl;
}

void Print(std::vector<int> &vlist) {
  for (int i = 0; i < vlist.size(); ++i) {
    std::cout << vlist[i];
  }
  std::cout << std::endl;
}

int Add(const int &a, const int &b) { return a + b; }

void TestInlineFunctions() {
  PROFILE_FUNCTION();
  for (int i = 0; i < 10000; ++i) {
    int ans = SquareInline(i);
    //   printf("ans = %d\n", ans);
  }
}

void TestRegularFunctions() {
  PROFILE_FUNCTION();
  for (int i = 0; i < 10000; ++i) {
    int ans = SquareRegular(i);
    //   printf("ans = %d\n", ans);
  }
}

void RunBenchmarks() {
  Instrumentor::Get().BeginSession("Profile");
  TestInlineFunctions();
  TestRegularFunctions();
  Instrumentor::Get().EndSession();
}
