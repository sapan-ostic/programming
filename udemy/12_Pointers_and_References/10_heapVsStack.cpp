#include <iostream>
using namespace std;

int main(){
    int *data = new int[2];
    
    data[4] = 3;

    for (int i{0}; i<5; i++)
        cout << data[i] << endl; 
        
    delete [] data;
}