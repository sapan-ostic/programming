#include <iostream>

int main(){
	int array[] {1,2,3,4,5};
	int *arr_ptr {array};
	
	std::cout << "array: " << array <<std::endl; //100 
    std::cout << "value of array: " << *array <<std::endl; //1 
    std::cout << "array_ptr: " << arr_ptr <<std::endl; //100 
    std::cout << "value at array ptr: " << *arr_ptr <<std::endl; //1
    
    // We can intercangebly use arr and pointer name
    std::cout << "value at 0: " << arr_ptr[0] << std::endl;
    std::cout << "value at 1: " << arr_ptr[1] << std::endl;
    std::cout << "value at 2: " << *(arr_ptr+2) << std::endl; 

	return 0;
}
