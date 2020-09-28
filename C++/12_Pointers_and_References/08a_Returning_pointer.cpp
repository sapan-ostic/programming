#include <iostream>
using namespace std; 

int * greater_value(int *a, int *b);

int main(){
	int num1 = 10;
    int num2 = 20;

    int *greater_ptr {nullptr};
    greater_ptr = greater_value(&num1, &num2);
    cout << "Greater number: " <<*greater_ptr << endl;  
    return 0;
}

int * greater_value(int *a, int *b){
	if (*a > *b)
        return a;
    else
        return b; 
}
