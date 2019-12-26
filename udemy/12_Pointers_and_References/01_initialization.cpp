#include <iostream>

int main(){
    int *int_ptr {};
    float *float_ptr {nullptr};
    char *char_ptr;

    std::cout<< *int_ptr << std::endl;
    std::cout<< *float_ptr << std::endl;
    std::cout<< *char_ptr << std::endl;

    return 0;
}