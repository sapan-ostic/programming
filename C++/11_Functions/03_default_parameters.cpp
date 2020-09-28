# include <iostream>
# include <vector>

// default parameters must be defined only in prototypes
void print_vector(std::vector<int> random_numbers, int N = 5);
void say_hello(int, int N = 2);


int main(){
	std::vector<int> numbers_list;
	
    // example 1
    say_hello(0);

    // example 2
    for (int i = 0; i < 7; i++) numbers_list.push_back(i);
    print_vector(numbers_list);
	std::cout << std::endl;
	print_vector(numbers_list, numbers_list.size());

	return 0;
}

void print_vector(std::vector<int> random_numbers, int N){
	for ( int i = 0; i < N ; i++){
	    std::cout<< random_numbers.at(i);
    } 
}

void say_hello(int temp, int N ){
    for(int i = 0; i < N; i++){
        std::cout<< "Hello" << std::endl; 
    }
}