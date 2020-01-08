#include <iostream>
#include <vector>

int main(){
    int *int_ptr {};
    float *float_ptr {nullptr};
    char *char_ptr; // uninitialized pointer

    std::cout << *char_ptr << std::endl; // garbage
    std::cout << "value of num ptr: " << int_ptr << std::endl; // 0
    std::cout << "address of num ptr: " << &int_ptr << std::endl; // 1000??

    int num = 6;
    int_ptr = &num;

    // We will see that value that the points at is stored right before the pointer

    std::cout << "value of num: " << num << std::endl; // 6, |num| = 4 bytes
    std::cout << "address of num: " << int_ptr << std::endl; // 996
    std::cout << "value of num ptr: " << int_ptr << std::endl; // 996
    std::cout << "address of num ptr: " << &int_ptr << std::endl; // 1000

    // dereferencing 
    std::cout << "value num ptr is pointing at: " << *int_ptr << std::endl; // 1000

    return 0;
}