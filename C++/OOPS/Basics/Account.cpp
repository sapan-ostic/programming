#include <iostream>
#include "Account.h"
#include "Savings.h"
using namespace std;

// Consttructor overloading
Account::Account(){
}

Account::Account(double bal_val)
    :balance{bal_val}{
}

Account::Account(std::string name):
    name{name}{
        
}

Account::Account(double bal_val, std::string name_val)
    :balance{bal_val}, 
     name{name_val}{
}



// Destructor
Account::~Account(){

} 

void Account::deposit(double amount){
    cout << "Depositing amount " << amount << " into the account" << endl;
    balance += amount; 
}

void Account::withdraw(double amount){
    cout << "Depositing amount " << amount << " into the account" << endl;
    balance -= amount;
}

int main(){
    // Test Public, Protected, Private inheritance
    // Public Inheritance: all attributes except private accessible
    // Protected Inheritance: all attributes except private are protected
    // Private Inheritance: all attributes except private are private  
    Account my_regular;
    Account my_savings("sbi");

    cout << my_savings.name << endl; 
    // cout << my_savings << endl;
    return 0;
}