//
// Created by Silin Li on 16:31 02/08/2020.
// 

#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

namespace test31{

bool IsStackWithPushPopOrder(const int *push, const int *pop, int len) {
    if (!push || !pop || len <= 0)
        return false;

    stack<int> s;
    const int *push_end = push + len;
    const int *pop_end = pop + len;

    s.push(*push);
    ++push;

    // 没处理完
    while (pop < pop_end) {
        // 没有遇到pop元素就一直压入
        while (s.top() != *pop && push < push_end) {
            s.push(*push);
            ++push;
        }

        if (s.top() == *pop) {
            s.pop();
            ++pop;
            continue;
        }
        else {
            return false;
        }
    }

    return true;
}
// ====================测试代码====================
void Test(const char *testName, const int *pPush, const int *pPop, int nLength, bool expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (IsStackWithPushPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};

    Test("Test1", push, pop, nLength, true);
}

void Test2() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};

    Test("Test2", push, pop, nLength, true);
}

void Test3() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};

    Test("Test3", push, pop, nLength, false);
}

void Test4() {
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};

    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5() {
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6() {
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7() {
    Test("Test7", nullptr, nullptr, 0, false);
}

void run() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
}

}

int main(int argc, char **argv) {
    test31::run();
    return 0;
}


