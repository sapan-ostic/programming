#ifndef _SAVINGS_H_
#define _SAVINGS_H_

#include "Account.h"

class Savings: public Account{

private:
    int sav_pvt {0};

protected:
    int sav_prott {0};

public:
    double interest_rate;
    Savings();
    ~Savings();
    void getInterest(int period);
};

#endif // _SAVINGS_H_