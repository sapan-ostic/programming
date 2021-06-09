#ifndef _PERSON_H_
#define _PERSON_H_

#include<iostream>
#include<string>

class Person{
private:
    double age;
    std::string name;
    double xp;
    static int num_person;
public:
    std::string *address;

    // getters
    std::string get_name() const {return name;}
    double get_age() const {return age;}
    double get_xp() const {return xp;}

    // setters
    void set_name(std::string& name_);
    void set_xp(double &xp_);
    void set_age(double &age_);

    // all arg constructor
    Person(std::string name_="None", double age_=0, double xp_=0, std::string address_="None"); 

    // Overloading using delegation, 
    // not required as constructor already takes 
    // default parameters
    // Person(std::string name_);

    // ~Person(); // Destructor
    ~Person();
    
    // Copy Constructor
    Person(const Person& source);

    // Move Constructor
    Person(Person &&source) noexcept;

    static int get_num_persons();
};

void Person::set_name(std::string& name_){name = name_;}
void Person::set_age(double& age_){age = age_;}
void Person::set_xp(double& xp_){xp = xp_;}

// all arg constructor
Person::Person(std::string name_, double age_, double xp_, std::string address_) 
    :age{age_}, 
    name{name_},
    xp{xp_}{
    address = new std::string{address_}; // allocate heap memory
    // *address = address_; // store value at heap memory
    std::cout << "Constructor called with name: " << name << std::endl;
    ++num_person;
    std::cout << "Active objects: " << get_num_persons() << std::endl;
}

Person::Person(const Person& source):
    name{source.name},
    xp{source.xp},
    age{source.age}{
    // Shallow Copy: create another pointer pointing to same area
    // address = source.address; 

    // Deep copy
    address = new std::string; //
    *address = *(source.address);
    std::cout << "Deep Copy constructor called wih name: "<< name << std::endl;
    ++num_person;
    std::cout << "Active objects: " << get_num_persons() << std::endl; 
}

Person::Person(Person &&source) noexcept
    :name{source.name},
    xp{source.xp},
    age{source.age}{    
    address = new std::string; 
    *address = *source.address;
    source.address = nullptr;
    std::cout << "Called Move Constructor with name: "<< source.name << std::endl;
    ++num_person;
}

Person::~Person(){
    std::cout << "Calling destructor with name: " << name << std::endl;
    num_person--;
    delete address;    
}

int Person::get_num_persons(){
    return num_person;
}
#endif // _PERSON_H_