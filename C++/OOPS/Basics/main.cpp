#include "Person.h"
#include <vector>

int Person::num_person = 0;

// example for copy constructor
void display_person(const Person a){
    // a is copy of frank
    std::cout << "Person name: " << a.get_name() << std::endl;
    // a's destructor is called
}

void vspace(){
    std::cout << std::endl;
}

int main(){
    // Constructor
    Person empty("empty");
    vspace();

    // Deep Copy Constructor
    Person copy_empty{empty}; // Copy Constructor msg
    vspace();

    // Shallow Copy Constructor fails here
    Person frank(std::string("Frank"), 10, 100, "John St"); // Constructor msg
    display_person(frank); // Copy Constructor msg, destructor msg
    std::cout << *(frank.address) << std::endl;
    vspace();

    // Move Constructor
    std::vector<Person> group;
    group.push_back(std::move(Person{"per1"})); // Move constructor
    group.push_back(Person{"per2"}); // Move Constructor
    vspace();
    std::cout << "Active objects: " << Person::get_num_persons() << std::endl;
    return 0; // destructor msgs
}