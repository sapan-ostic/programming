#include <iostream>
#include <vector>

void double_num1(int *const int_ptr); // not allowed to change pointer 
void double_num2(int &num);
void append_data(std::vector<int> &, int);
void append_data(int array[], int num, int pos);

int main(){
	
    // passing pointer of int 
    int num = 5;
    double_num1(&num);
    std::cout << num << std::endl; // 10

    // passing int by reference 
    double_num2(num); // cant use double_num2(5); no reference to r-value
    std::cout << num << std::endl; // 20

    // passing vector by reference 
    std::vector< std::vector<int> > vect {{0,1},{0}}; // 2D vector
    append_data(vect[1], 5);
    std::cout << (vect.back()).back() << std::endl; // 5
	
    // pointer of Array is passes by default
    int array[5] {0,1,2,0,1};
    int pos = 2;
    append_data(array, 6, pos);
    std::cout << array[pos] << std::endl; // 6

    return 0;
} 

void double_num1(int *int_ptr){
    *int_ptr *= 2;  
}

void double_num2(int &num){
    num *= 2; 
}

void append_data(std::vector<int>& vect, int num){
	vect.push_back(num);
}

void append_data(int array[], int num, int pos){
    array[pos] = num;
}