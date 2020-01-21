#include <iostream>
using namespace std;


int main(){
	string array[5] {"Sam", "John", "Larry", "Smith", "Jacob"};
	
	for(auto name:array)
		name = "Funny";

    cout << array[0] << endl;

	for(auto &name:array) // const &name:array will give compile error
		name = "Funny";

	cout << array[0] << endl;
	return 0;
}

