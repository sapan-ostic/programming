#pragma once
#include <iostream>
#include <queue>

// Non-template functions
template <typename T, size_t size> void PrintArray(T (&list)[size]) {
  std::cout << "[";
  for (int i = 0; i < size - 1; ++i) {
    std::cout << list[i] << ", ";
  }
  std::cout << list[size - 1] << "]" << std::endl;
}