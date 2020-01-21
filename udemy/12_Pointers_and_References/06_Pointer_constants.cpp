#include <iostream>
#include <vector>

void pointerToConst();
void Constpointer();

int main(){
	pointerToConst();
    Constpointer();
   
    return 0;
} 

void pointerToConst(){
	int low_score = 5;
    int high_score = 8;
	const int *int_ptr {&low_score}; // value at the pointer is const
		
	std::cout << "Pointer: " << int_ptr << std::endl; 
    // *int_ptr = 10; // error
    // low_score = 10; // Works !!
    int_ptr = &high_score;
    std::cout << "Pointer: " << int_ptr << std::endl;
}

void Constpointer(){
	int low_score = 5;
    int high_score = 8;
	int *const int_ptr {&low_score}; // pointer is const
		
	std::cout << "Pointer: " << int_ptr << std::endl; 
    low_score = 2; 
    // int_ptr = &high_score; // error
    std::cout << "Pointer: " << int_ptr << std::endl;
}