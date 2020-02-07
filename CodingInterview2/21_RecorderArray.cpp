//
// Created by Silin Li on 17:48 02/07/2020.
// 

#include <iostream>

using namespace std;

namespace test21{
/**
 * @brief 调整数组，使得奇数在前，偶数在后
 * @param Func return true if number is odd
 */
template<typename Func>
void RecoderArray(int *data, size_t len, Func func) {
    if (!data || len <= 0) {
        return;
    }

    int *begin = data;
    int *end = data + len - 1;
    while (begin < end) {
        while (begin < end && func(*begin)) {
            ++begin;
        }
        while (begin < end && !func(*end)) {
            --end;
        }

        if (begin < end) {
            std::swap(*begin, *end);
        }
    }
}

void RecoderArrayEven(int *data, size_t len) {
    auto isOdd = [](int num) -> bool { return num & 0x01; };

    RecoderArray(data, len, isOdd);
}


// ====================测试代码====================
void PrintArray(int numbers[], int length) {
    if (length < 0)
        return;

    for (int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(char *testName, int numbers[], int length) {
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    int *copy = new int[length];
    for (int i = 0; i < length; ++i) {
        copy[i] = numbers[i];
    }

    PrintArray(numbers, length);
    RecoderArrayEven(numbers, length);
    PrintArray(numbers, length);

    delete[] copy;
}
void Test1() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2() {
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3() {
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4() {
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5() {
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6() {
    Test("Test6", nullptr, 0);
}

void run() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
}
}


int main(int argc, char **argv) {
    test21::run();
    return 0;
}

