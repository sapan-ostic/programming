#include <iostream>
#include "Savings.h"
using namespace std;

Savings::Savings()
    :interest_rate{0.05}{
    name = "savings";
}

Savings::~Savings(){

}

void Savings::getInterest(int period){
    double new_balance =  balance+balance*interest_rate*period;
    cout << "New balance after interest for period " << period << " is " << new_balance << endl;
    cout << acc_prott << endl;
    // cout << acc_pvt << endl;
}