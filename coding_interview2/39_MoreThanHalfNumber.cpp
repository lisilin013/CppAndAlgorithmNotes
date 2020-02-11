//
// Created by Silin Li on 22:24 02/11/2020.
// 

#include <iostream>
#include "Sort.h"
using namespace std;


namespace test39{

bool CheckMoreThanHalf(int *numbers, int length, int middle) {
    int times = 0;
    for (int i = 0; i < length; ++i) {
        if (numbers[i] == middle)
            ++times;
    }
    return times*2 > length;
}
/**
 *
 * @param numbers
 * @param length
 * @return -1 means input are not illegal
 */
int MoreThanHalfNum_Partition(int *numbers, int length) {
    if (!numbers || length <= 0)
        return 0;

    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Algorithm::Partition(numbers, start, end);
    while (index != middle) {
        if (index > middle) {
            end = index - 1;
            index = Algorithm::Partition(numbers, start, end);
        }
        else {
            start = index + 1;
            index = Algorithm::Partition(numbers, start, end);
        }
    }

    int result = numbers[middle];
    return CheckMoreThanHalf(numbers, length, result) ? result : 0;
}

int MoreThanHalfNum_LawOfNumbers(int *numbers, int length) {
    if (!numbers || length <= 0)
        return 0;

    int result = numbers[0];
    int times = 1;
    for (int i = 1; i < length; ++i) {
        if (times == 0) {
            result = numbers[i];
            times = 1;
        }
        else if (numbers[i] == result) {
            ++times;
        }
        else {
            --times;
        }
    }

    return CheckMoreThanHalf(numbers, length, result) ? result : 0;
}

// ====================测试代码====================
void Test(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result = MoreThanHalfNum_Partition(numbers, length);
    if(result == expectedValue )
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test for solution2: ");
    result = MoreThanHalfNum_LawOfNumbers(copy, length);
    if(result == expectedValue )
        printf("Passed.\n");
    else
        printf("Failed.\n");

    delete[] copy;
}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test2()
{
    int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test5()
{
    int numbers[] = {1};
    Test("Test5", numbers, 1, 1, false);
}

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, 0, 0, true);
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
    test39::run();
    return 0;
}

