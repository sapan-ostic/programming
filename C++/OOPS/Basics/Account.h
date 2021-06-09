#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account {

private:
    int acc_pvt {0};

protected:
    int acc_prott {0};

public:
    double balance;
    std::string name;  
    void deposit(double amount);
    void withdraw(double amount);

    Account(); // constructor
    Account(double balance); // overloading
    Account(std::string name); // overloading
    Account(double balance, std::string name); // overloading
    
    ~Account(); // destructor
};

#endif //_ACCOUNT_H_
