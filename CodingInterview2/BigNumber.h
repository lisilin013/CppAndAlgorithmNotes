//
// Created by Silin Li on 13:41 02/06/2020.
// 

#ifndef CODINGINTERVIEW_BIGNUMBER_H
#define CODINGINTERVIEW_BIGNUMBER_H
#include <iostream>
#include <cassert>
#include <cstring>

namespace Algorithm{

class BigNumber {
public:
    friend std::ostream &operator<<(std::ostream &os, const BigNumber &big_number);
public:
    explicit BigNumber(const std::string &number);

    BigNumber &operator+(const BigNumber &big_number);
    BigNumber &operator-(const BigNumber &big_number);
    BigNumber &operator*(const BigNumber &big_number);
    BigNumber &operator/(const BigNumber &big_number);
    BigNumber &operator%(const BigNumber &big_number);

    BigNumber &operator+=(const BigNumber &big_number);
    BigNumber &operator-=(const BigNumber &big_number);
    BigNumber &operator*=(const BigNumber &big_number);
    BigNumber &operator/=(const BigNumber &big_number);
    BigNumber &operator%=(const BigNumber &big_number);


    BigNumber &operator++();
    BigNumber &operator--();


private:
    int length_;
    int *number_;
    bool sign_;//false means '-' ; true means '+'
};


}
#endif //CODINGINTERVIEW_BIGNUMBER_H
