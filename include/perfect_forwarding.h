#pragma once
#include "base_class.h"
#include <iostream>
#include <string>

class TemplatedEntity {
public:
  // Member Template
  template <typename T1, typename T2>
  TemplatedEntity(T1 &&name, T2 &&obj)
      : name_{std::forward<T1>(name)}, obj_{std::forward<T2>(obj)} {
    std::cout << "Constructor: " << __PRETTY_FUNCTION__ << std::endl;
  }

  ~TemplatedEntity() {
    std::cout << "Destructor: " << __PRETTY_FUNCTION__ << std::endl;
  }

private:
  std::string name_;
  Base obj_;
};

class Entity {
public:
  // Copy-Copy Constructor, for both l-values
  Entity(const std::string &name, const Base &obj) : name_{name}, obj_{obj} {
    std::cout << "Copy-Copy Constructor: " << __PRETTY_FUNCTION__ << std::endl;
  }

  // Copy-Move Constructor, for name (l-value) obj (r-value)
  Entity(std::string &name, const Base &&obj)
      : name_{name}, obj_{std::move(obj)} {
    std::cout << "Copy-Move Constructor: " << __PRETTY_FUNCTION__ << std::endl;
  };

  // Move-Copy Constructor, for name (r-value) obj (l-value)
  Entity(std::string &&name, const Base &obj) : name_{name}, obj_{obj} {
    std::cout << "Move-Copy Constructor: " << __PRETTY_FUNCTION__ << std::endl;
  };

  // Move-Move Constructor, for both r-values
  Entity(std::string &&name, Base &&obj) : name_{name}, obj_{std::move(obj)} {
    std::cout << "Move-Move Constructor: " << __PRETTY_FUNCTION__ << std::endl;
  };
  ~Entity() { std::cout << "Destructor: " << __PRETTY_FUNCTION__ << std::endl; }

private:
  std::string name_;
  Base obj_;
};
