#include <iostream>

int main(){
	int array[] {0,1,2,3,4,-1};
	int *int_ptr {array};

    while(*int_ptr != -1){
        std::cout<< *int_ptr++<< std::endl; //post increment   
    } 
	
    int_ptr = array;

	while(*int_ptr != -1){
        std::cout<< *++int_ptr<< std::endl; //value at next memory 
    }

    // POINTER TO CONSTANTS
    int low_score {35};
    int high_score {90};

    const int *int_ptr {&high_score};
    

	return 0;
}
