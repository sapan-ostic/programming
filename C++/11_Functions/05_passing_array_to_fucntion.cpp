#include <iostream>

void zeros(int numbers [], int size);
void print(int arr [], int size);

int main(){
	int numbers[5] = {1,2,3,4,5};

	std::cout<< "numbers at " << numbers<< std::endl;

	zeros(numbers, 5);
	print(numbers, 5);

 
	return 0;
}

void zeros(int arr [], const int size){   // const cant be defined in prototypes  
	for (int i = 0; i<size; i++){
		arr[i] = 0;
	}
}

void print(int arr [], int size){
	for (int i = 0; i<size; i++){
		std::cout << arr[i] << " " << std::endl;
	}
}
