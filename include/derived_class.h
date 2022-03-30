#pragma once
#include "base_class.h"
#include <iostream>

/**
 * @brief Simple derived class example
 */
class Derived : public Base {
public:
  Derived(int var) : Base(var) {
    std::cout << "Derived Constructor: " << __PRETTY_FUNCTION__ << std::endl;
  }

  // Copy Constructor
  Derived(const Derived &other) : Base(other) {
    std::cout << "Derived Copy Constructor: " << __PRETTY_FUNCTION__
              << std::endl;
  }

  // Move Constructor
  Derived(Derived &&other) : Base(other) {
    std::cout << "Derived Move Constructor: " << __PRETTY_FUNCTION__
              << std::endl;
  }

  ~Derived() {
    std::cout << "Derived Destructor: " << __PRETTY_FUNCTION__ << std::endl;
  }
};
