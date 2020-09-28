#include <iostream>
#include <vector>

struct Vector3{
	float x, y, z;
	Vector3()
		: x(10), y(11), z(12) {}
};

int main(){

    // Stack
    int num = 5;
    int array[5] {0,1,2,3,4};
    std::vector<int> vect {100, 101, 102};  
	Vector3 vect3;

	// Heap 
	int *hnum = new int;
    *hnum = 5;
	
	int *harray = new int [5];
	std::vector<int> *hvect = new std::vector<int>; 
	Vector3 *hvect3 = new Vector3;
	
	// deleting memory
	delete hnum;
	delete [] harray;
 	delete hvect;
	delete hvect3;

    return 0;
}
