// Function definition and prototypes

# include<iostream>

// using namespace std;

// prototypes
void say_hello();
void say_world();

int main(){
	say_hello();
	return 0;
}

void say_hello(){
	std::cout<< "Hello ";
	say_world();
}

void say_world(){
	std::cout<< "World" << std::endl;
}


