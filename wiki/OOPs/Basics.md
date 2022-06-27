[OOPS](https://github.com/sapan-ostic/programming/wiki/OOPS) < [Basics](https://github.com/sapan-ostic/programming/wiki/OOPS:-Basics) > [Inheritance](https://github.com/sapan-ostic/programming/wiki/OOP:-Inheritence) 

### Why OOP?
1. Encapsulation: OOP binds Data and functions that manipulate that data together.
2. Information Hiding: private and protected members of class
3. Inheritance: 
4. Polymorphism:

### 1. Declaring Classes and Objects
```C++
Class Account{
// private members by default
   double m_ssn; 

protected:
   // attributes
   int m_balance;
   std::string m_name;

public:   
   // methods
   void print_balance(){
       std::cout << "balance: "<< m_balance << std::endl;
   }

   // method prototype
   void PrintName();
   void CheckSSN(double& ssn);
};

Account::PrintName(){
    std::cout << "account holder name: " << m_name << std::endl;
}

Account::CheckSSN(double& ssn_){
   if(m_ssn==ssn)
      std::cout << "identity verified" << std::endl;
   else
      std::cout << "identity not valid" << std::endl;
}

// Creating class object
Account sbi;

// on heap
Account *hdfc = new Account(); 
delete hdfc;
```

### Accessing members
1. dot operator: `object.member;`
2. `->` operator: `objptr->member` or `(*objptr).member` (dereferencing)
```C++
sbi.balance = 100;
hdfc->balance = 100;
(*hdfc).name = "Pradeep";
hdfc->print_balance(); // 100
```

### Access modifiers
1. public: accessible everywhere
2. private: only available to class **(default)**
3. protected: similar to private (more in inheritance)

### Header Files for Classes
To avoid duplicate include guards of class header files using:
```C++ 
#ifdef _ACCOUNT_H_
#define _ACCOUNT_H_

// Class Account

# endif // _ACCOUNT_H_
```
### Constructor and Destructor
1. Function overloading is possible
2. Constructors and destructors have no return.
3. By default, compiler builds empty constructor with attributes initialized randomly.
4. 
```C++
Account::Account(); // no args
Account::Account(double balance); // 1 args
```
4. In the following approach, the constructor first initializes attributes with random values and the assigns the user defined values.
```C++
Account::Account(){
   double balance = 100; // initialized with garbage and then assigned value
   std::string name = "sbi";
}
``` 

### Constructor Initialization list
```C++
Account::Account():
    balance{100},
    name{"hdfc"}
{
  // do something here 
}
```

### Constructor delegation
Use most versatile constructor to create other constructors.
```C++
Account::Account(double bal_val, std::string name_val):
    name{name_val},
    balance(bal_val){
}
Account::Account(double bal_val):
    Account{bal_val, ""}{
}
Account::Account(std::string name_val):
    Account{0, name_val}{
}
```

### Default parameters
Most simple method is to define constructor with default arguments.
```C++
Account::Account(std::string name="None", double balance=0);
```
**Note: Use default arguments in method prototype only.**


### Copy Constructors:
1. Copy of the object is made and done by C++ in-built copy-constructors:
   1. Passed by value
   ```C++
   diplay_account(Account a){
   // a is a copy of sbi
   // use p 
   // destructor for p here
   }
   Account sbi;
   display_account(sbi);
   ```
   2. Return
   ```C++
   Account create_fd_account(){
   Account fd(0, "FD");
   return fd;  // copy of fd is returned and destructed 
   }
   ```
2. User defined Copy constructor
```C++
Account::Account(const Account &source)
    :name{source.name},
     balance{source.balance}{
}
// OR using delegation
Account::Account(const Account &source)
    :Account{source.name, source.balance}{
}
```
3. For pointer data members, pointer will be copied and not the data it pointing to. 

### Shallow Vs Deep Copy
1. memberwise copy, each member data is copied from source
2. pointer is copied, not what it is 

**Shallow Copy**
```C++
class Shallow{
private:
   int *data; // raw pointer
public:
   Shallow(int d); // constructor
   Shallow(const Shallow &source); // copy constructor
   ~Shallow(); // destructor
}

Shallow::Shallow(int d){
   data = new int; // allocate storage
   *data = d; // assign value 
}

Shallow::Shallow(const Shallow &source):
   data{source.data}{
   std::cout << "Copy constructor-shallow is called" << std::end;
}

Shallow::~Shallow(){
   delete data; // clear heap memory
   std:: cout << "Destructor is called" << std::endl;
}
```
** Problem: both data and source.data point to the same area.**
Thus, when the second pointer is destroyed/goes out of scope, the data is lost upon calling the destructor. This happens because when the memory is cleared for the first pointer it is marked as free and has garbage value.

**Deep copy**
1. Copy the pointed-to-data.
2. Each pointer will have a unique storage in the heap
3. Use deep copy when you have raw pointers in the class data member.
```C++
class Deep{
private:
   int *data; // raw pointer
public: 
   Deep(int d); //constructor
   Deep(const Deep& source); // copy constructor
   ~Deep();
}
Deep::Deep(int d){
   data = new int{d};
}

Deep::Deep(const Deep& source){
   data = new int; 
   *data = *(source.data);
}

Deep::~Deep(){
   delete data;
}
```  
 
### Move Constructor
Moves data from the source to current object and nulls out the pointer at the source. 
```C++
class Move{
private:
   int *data; 
public:
   void set_data_value(int d){*data = d;}
   int get_data_value(){return *data;}
   Move(int d); // constructor
   Move(const Move &source); // copy constructor
   Move(Move &&source); //Move Constructor
   ~Move(); // Destructor
}

Move::Move(Move &&source):
   data{source.data}{
   source.data = nullptr; 
}
```
**Note: Move constructors will called for r-values not copy constructors**

### Const for class
Suppose a function takes in const parameters. The class methods though dont change any members but the compiler may think that method may change the object. Hence best practice is to 
```C++
void Account::get_balance() const {
   return balance;
}
```

### Static for a class
A static variable can be crucial at places like counting number of objects created. Instead of creating a variable outside the class it is much easier to create one inside the class.
```C++ 
private:
static int count_objects;
```

### Struct 
Structs are same as class except all members are public.
```
struct Person{
   std::string name;
   std::string get_name();
   Person(std::string name):
      name(name){
   };
}
```
### Friend of a class in C++
1. Friend are functions or other classes that have access to private members of a class. 
2. Can be independent functions or methods of other class.
3. Must be explicitly declared in the class in the prototype.
4. Friendship is not symmetric. A is friend of B but not vice versa. 
5. Friendship is not transitive. A is friend of B, B is friend of C but A and C are not friends.
```C++
class Account{
   friend void display_person(Person &p);
}
```
6. Note that friend functions would still need the class object in order to access the private attributes. Otherwise we get not-defined error.
**ToDo: Add implementation details for class ** 
 
[OOPS](https://github.com/sapan-ostic/programming/wiki/OOPS) < [Basics](https://github.com/sapan-ostic/programming/wiki/OOPS:-Basics) > [Inheritance](https://github.com/sapan-ostic/programming/wiki/OOP:-Inheritence) 
