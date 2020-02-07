//
// Created by Silin Li on 14:06 02/06/2020.
//
#include <iostream>
using namespace std;

namespace test19{

bool MatchCore(const char *str, const char *pattern) {
    if (*pattern == '\0') {//pattern done
        return *str == '\0';
    }

    // pattern is not done
    if (*(pattern + 1) == '*') {
        if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
            return MatchCore(str + 1, pattern + 2) // move no the next state
                   || MatchCore(str + 1, pattern)  // stay on the current state
                   || MatchCore(str, pattern + 2); // ignore a '*'
        }
        else {
            return MatchCore(str, pattern + 2);    // ignore a '*'
        }
    }
    else {
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            return MatchCore(str + 1, pattern + 1);
    }

    return false;
}
bool Match(const char *str, const char *pattern) {
    if (!str || !pattern)
        return false;

    return MatchCore(str, pattern);
}

// ====================测试代码====================
void Test(const char *testName, const char *string, const char *pattern, bool expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (Match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void run() {
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);
}
}

int main(int argc, char **argv) {
    test19::run();
    return 0;
}

