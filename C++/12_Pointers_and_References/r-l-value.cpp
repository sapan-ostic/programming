#include <iostream>
using namespace std;

int square(int &num){
    return num*num;
}

int main(){
	int x = 10; // x: l-value, 10:r-value 
	int &ref1 = x;
	ref1 = 100; // can be changes as ref1 refers to x

	cout << "value of x: " << x << endl;
	
	// int &ref2 = 100; //compile Error: no reference to number
    
    int sq = square(x);
    // sq = square(100); invalid as input is a reference  
    
    cout << "Square of x: " << sq << endl;
	return 0;
}
