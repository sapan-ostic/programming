#include <iostream>
#include <chrono>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0])) 

using namespace std;

void findNemo(string array[], int);

int main(){
	string nemo[]  = {"Nemo", "Kathy"};
    string large [10] {};
        
    // Begin Timer
    // int size = sizeofArray(large);
	auto start = chrono::steady_clock::now();
    
    int size = NELEMS(large);
    std::fill_n(large, size, "Nemo");
    
    findNemo(large, size); 

    auto end = chrono::steady_clock::now();
    std::cout << chrono::duration <double, milli> (end-start).count() << " ms" << endl;
    return 0;
}

void findNemo(string array [], int size){
    cout << "Size of array = " <<  size << endl; 
    for(int i=1; i<size; i++){
        if (array[i] == "Nemo")
            std::cout << "Found Nemo !" << endl; 	
    }
}