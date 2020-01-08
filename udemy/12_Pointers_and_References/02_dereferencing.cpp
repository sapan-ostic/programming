#include <iostream>
#include <vector>

void printVect(const std::vector<std::string> &vect); //passing by ref 

int main(){
	std::vector<std::string> laptops {};
    std::vector<std::string> *vect_ptr {&laptops};

    (*vect_ptr).push_back("Dell XPS 13");
    (*vect_ptr).push_back("Surface Book 2");
    (*vect_ptr).push_back("MacBook Pro");

    // following works only if initialized
    // (*vect_ptr)[2] = "MacBook Pro";

	printVect(laptops);
    return 0;
}

void printVect(const std::vector<std::string> &vect){
    // for(int i {0}; i<vect.size(); i++)
    // 	std::cout<<vect[i] << std::endl;

    for(auto elem:vect)
        std::cout<< elem << std::endl;      
}