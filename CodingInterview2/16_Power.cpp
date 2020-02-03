//
// Created by Silin Li on 22:43 02/03/2020.
// 

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。
namespace test16{
bool Equal(double num1, double num2) {
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

double PowerWithUnsignedExponentIterative(double base, unsigned exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = base;
    bool odd = false;
    if (exponent%2)//奇数
        odd = true;

    while (exponent > 1) {
        result = result*result;
        exponent /= 2;
    }

    if (odd)
        result *= base;
    return result;
}

double PowerWithUnsignedExponentRecursive(double base, unsigned exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = PowerWithUnsignedExponentRecursive(base, exponent/2);
    result *= result;
    if (exponent & 0x01) {//奇数
        result *= base;
    }
    return result;
}


bool InvalidInput = false;
double Power(double base, int exponent) {
    // base=0
    if (Equal(base, 0.0) && exponent < 0) {
        cout << "Invalid Input!\n";
        InvalidInput = true;
        return 0;
    }

    double result = PowerWithUnsignedExponentRecursive(base, std::abs(exponent));
    if (exponent < 0)
        result = 1.0/result;

    return result;
}

// ====================测试代码====================
void Test(const char *testName, double base, int exponent, double expectedResult, bool expectedFlag) {
    double result = Power(base, exponent);
    if (Equal(result, expectedResult) && InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}
void run() {
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);
}
}

int main(int argc, char **argv) {
    test16::run();
    return 0;
}

