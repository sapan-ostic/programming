/**
 * shared_ptr<T>
 * - Points to an object of type T on the heap
 * - No Unique: many shared_ptrs points to the same object
 * - shared ownership
 * - When the count is 0, the managed object on the heap is destroyed.
 * - small overhead for the counter
 * - useful methods: use_count(), reset()
 * - unlike unique_ptr, shared_ptr can be copied, assigned, moved
 */

#include <iostream>
#include <memory>
#include <vector>

class Account{
public:
    float balance;
    Account(float init_balance){
        balance = init_balance;
    }
    void credit(float amount){
        balance += amount;
    }
    void debit(float amount);
};

void Account::debit(float amount) {
    balance -= amount;
}

int main(){
    std::shared_ptr<int> p1 = std::make_shared<int>(100);
//     std::shared_ptr<int> p1 {new int {100}}; // non-preferred method to declare a pointer

    std::cout<< "value at p1: " << *p1 << std::endl; //100, p1 owns the object at the heap
    *p1 = 200;
    std::cout<< "new value at p1: " << *p1 << std::endl; // 200

    // Some useful methods: use_count(), reset()
    std::cout << "No. of shared_ptr objects managing the object: " << p1.use_count() << std::endl; // 1
    std::shared_ptr p2 {p1}; // shared ownership
    std::cout << "No. of shared_ptr objects managing the object: " << p1.use_count() << std::endl; // 2

    p1.reset(); // p1 is nulled out
    std::cout << "p1 count after resetting: " << p1.use_count() << std::endl; // 0
    std::cout << "p2 count after resetting: " << p2.use_count() << std::endl; // 1

    // assign, copy & move
    std::vector<std::shared_ptr<int>> vec;
    vec.push_back(p2); // OK - copy is allowed
    std::cout << "p2 count after appending to vector: " << p2.use_count() << std::endl; // 2


    // Using Class object
    std::shared_ptr<Account> acct_ptr = std::make_shared<Account>(100);
    std::cout << "Current Balance: " << acct_ptr->balance << std::endl;
    acct_ptr->credit(100);
    std::cout << "Balance after crediting: " << acct_ptr->balance << std::endl;

    return 0;
} // memory is automatically cleared.