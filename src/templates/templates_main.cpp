/**
 * @file templates_main.cpp
 * @author Sapan Agrawal (ssagrawal@wpi.edu)
 * @brief
 * @version 0.1
 * @date 2022-03-26
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * Templates
 * - avoids rewriting functions/class every type, compiler deduces the type and
 * create functions/class for the specific types used by the user.
 *
 */

#include "array.h"
#include "base_class.h"
#include <iostream>
#include <string.h>
#include <vector>

#define DEBUG 1

// (a) Base Template
template <typename T> T Max(T x, T y) {
  T ret = y;
  if (x > y) {
    ret = x;
  }
  if (DEBUG) {
    std::cout << "(a) " << __PRETTY_FUNCTION__ << std::endl;
  };
  return ret;
}

// (b) Explicit Instantiation
// Here, we force compiler to create an instantiation of type char
template char *Max(char *x, char *y);

// (c) Explicit Specialization template <>
// Use when we want to overwrite the implementation in the Base template for a
// specific data type.
template <> const char *Max(const char *x, const char *y) {
  if (DEBUG) {
    std::cout << "(c) " << __PRETTY_FUNCTION__ << std::endl;
  };
  return strcmp(x, y) > 0 ? x : y;
}

// (d) Overloaded Template
template <typename T> std::vector<T> Max(std::vector<T> &x, std::vector<T> &y) {
  if (DEBUG) {
    std::cout << "(d) " << __PRETTY_FUNCTION__ << std::endl;
  };

  std::vector<T> ret;
  for (int i = 0; i < x.size(); ++i) {
    if (x[i] > y[i]) {
      ret.push_back(x[i]);
    } else {
      ret.push_back(y[i]);
    }
  }
  return ret;
}

int main() {
  // Example template instantiation
  Max(4, 8);     // (a)
  Max(4.6, 8.0); // (a)

  // overwrite argument deduction by specifying type
  int max_int = Max<int>(4.6, 5.1); // (a)
  printf("Overwrite argument deduction: Max<int>(4.6, 5.1) = %d\n", max_int);

  // Explicit instantiation
  std::cout << "\nExplicit instantiation\n";
  char *b{new char('B')};      // address 100
  char *a{new char('A')};      // address 101
  auto s = Max(a, b);          // (b) compares the address
  std::cout << s << std::endl; // outputs "A", even for const char* i.e. strings
  delete a, b;

  // Thus, we need special implementation for pointers/references.
  // Explicit Specialization (s)
  std::cout << "\nExplicit Specialization\n";
  const char *b1{"B"};          // address 100
  const char *a1{"A"};          // address 101
  auto s1 = Max(a1, b1);        // (c) compares the address
  std::cout << s1 << std::endl; // outputs "B"

  // Overloaded Templates
  std::cout << "\nOverloaded Templates\n";
  std::vector<int> v1{5, 2, 6, 3, 7, 4};
  std::vector<int> v2{7, 1, 5, 6, 3, 2};
  Max(v1, v2); // (d)

  // Non-Type Template example
  std::cout << "\nNon-Type Templates\n";
  int list[] = {1, 2, 3, 4, 5, 6};
  PrintArray(list);

  return 0;
}
