#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include "vector"

class BigNumber
{
private:
    //vector<int> number;
public:
    BigNumber();
    void setNumb (long long int innumb);
    long long int getNumb();
    void mult (BigNumber numb2);
    void mod (BigNumber numb2);
};

#endif // BIGNUMBER_H
