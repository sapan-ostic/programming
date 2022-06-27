# std::iterators
### References: 
1. [https://en.cppreference.com/w/cpp/iterator](https://en.cppreference.com/w/cpp/iterator)

## Basics
1. used to access elements by their positions
2. provide overloaded operators such as ++, --, *. etc
3. `container.end()` points to the position beyond the last element. Thus, never derefence the iterator created bt `end()`. It is however very useful for checking the success/failure of various `std::algorithm`. If the algorithm returns the `end()` iterator, it means it failed. 