#pragma once
#include "util.h"
#include <iostream>

/**
 * @brief Simple base class example
 */
class Base {
public:
  Base(int var) : var_(var) {
    space_;
    std::cout << "Constructor: " << __PRETTY_FUNCTION__ << std::endl;
    var_ptr_ = new int(var);
  }

  // Copy Constructor
  Base(const Base &other) : var_(other.var_) {
    std::cout << "Copy Constructor: " << __PRETTY_FUNCTION__ << std::endl;
    var_ptr_ = new int(*other.var_ptr_);
  }

  // Move Constructor
  Base(Base &&other) : var_(std::move(other.var_)), var_ptr_(other.var_ptr_) {
    std::cout << "Move Constructor: " << __PRETTY_FUNCTION__ << std::endl;
    other.var_ptr_ = nullptr;
  }

  // Helper methods
  int GetValue() { return var_; }
  int *GetPtr() { return var_ptr_; }

  ~Base() {
    std::cout << "Destructor: " << __PRETTY_FUNCTION__ << std::endl;
    delete var_ptr_;
  }

protected:
  int var_;
  int *var_ptr_;
};
