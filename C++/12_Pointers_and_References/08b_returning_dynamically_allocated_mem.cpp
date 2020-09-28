#include <iostream>
using namespace std;

int* create_array(int size, int init);

int main(){
    int *array = create_array(5,10);	
    cout << array[4] << endl;
    delete [] array;
    return 0; 
}

int* create_array(int size, int init){
    int *arr_ptr = new int [size]; 
    for(int i{0}; i<size; i++)
        *(arr_ptr+i) = init;		
    return arr_ptr; 
}
