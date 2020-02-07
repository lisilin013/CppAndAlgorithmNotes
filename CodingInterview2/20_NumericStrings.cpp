//
// Created by Silin Li on 17:20 02/07/2020.
// 

#include <iostream>
#include <string>

using namespace std;


namespace test20{
bool ScanUnsignedInteger(const char *&str) {
    const char *before = str;
    while (*str != '\0' && *str >= '0' && *str <= '9') {
        ++str;
    }
    return str > before;
}
bool ScanSignedInteger(const char *&str) {
    if (*str == '+' || *str == '-') {
        ++str;
    }
    return ScanUnsignedInteger(str);
}
/**
 * @brief
 * -123.45e+6
 * [A].[B]e[C]
 * A: +/- 0~9
 * B: 0~9
 * C: +/- 0~9
 */
bool IsNumericString(const char *str) {
    if (!str)
        return false;
    // [A]
    bool numeric = ScanSignedInteger(str);
    //[B]
    if (*str == '.') {
        ++str;
        // 0.123
        // 123.0
        // 123.123
        // 三种情况都合适，所以用||
        numeric = ScanUnsignedInteger(str) || numeric;
    }
    //[C]
    if (*str == 'e' || *str == 'E') {
        ++str;
        // 123e123
        // 0.e123 [x]
        // 123e   [x]
        // 也就是指数要求e前面必须有合法的数字
        numeric = ScanSignedInteger(str) && numeric;
    }
    return numeric && *str == '\0';
}


// ====================测试代码====================
void Test(const char *testName, const char *str, bool expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (IsNumericString(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


void run() {
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);


}
}


int main(int argc, char **argv) {
    test20::run();
    return 0;
}

