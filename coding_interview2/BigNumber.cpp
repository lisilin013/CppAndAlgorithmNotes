//
// Created by Silin Li on 13:57 02/06/2020.
// 

#include "BigNumber.h"

namespace Algorithm{
BigNumber::BigNumber(const std::string &number) : length_(number.size()) {
    // 根据规则解析数字
}

BigNumber &BigNumber::operator+(const BigNumber &big_number) {
}
BigNumber &BigNumber::operator-(const BigNumber &big_number) {
}
BigNumber &BigNumber::operator*(const BigNumber &big_number) {
}
BigNumber &BigNumber::operator/(const BigNumber &big_number) {
}
BigNumber &BigNumber::operator%(const BigNumber &big_number) {
}


BigNumber &BigNumber::operator+=(const BigNumber &big_number) {
}
BigNumber &BigNumber::operator-=(const BigNumber &big_number) {
}
BigNumber &BigNumber::operator*=(const BigNumber &big_number) {
}
BigNumber &BigNumber::operator/=(const BigNumber &big_number) {
}
BigNumber &BigNumber::operator%=(const BigNumber &big_number) {
}


BigNumber &BigNumber::operator++() {
}
BigNumber &BigNumber::operator--() {
}

std::ostream &operator<<(std::ostream &os, const BigNumber &big_number) {

    return os;
}

}

namespace BigNumberTest{
void run() {

}
}
int main(int argc, char **argv) {
    BigNumberTest::run();
    return 0;
}

