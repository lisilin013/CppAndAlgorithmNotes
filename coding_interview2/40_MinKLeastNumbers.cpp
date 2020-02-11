//
// Created by Silin Li on 22:55 02/11/2020.
// 

#include <iostream>
#include <set>
#include <vector>
#include "Sort.h"

using namespace std;

namespace test40{

/**
 * @brief 时间复杂度O(n)
 */
void GetKLeastNumbers_Partition(int *input, int n, int *output, int k) {
    if (!input || n <= 0 || !output || k <= 0 || k > n)
        return;

    // using partition algorithm in quick sort
    int start = 0;
    int end = n - 1;
    int index = Algorithm::Partition(input, start, end);
    while (index != k-1) {
        if (index > k-1) {
            end = index - 1;
            index = Algorithm::Partition(input, start, end);
        }
        else {
            start = index + 1;
            index = Algorithm::Partition(input, start, end);
        }
    }

    std::copy(input, input + k, output);
//    for (int i = 0; i < k; ++i) {
//        output[i] = input[i];
//    }
}


/**
 * @brief 适合处理海量数据，时间复杂度O(nlog(k))
 * 使用红黑树，需要实时替换掉最大的
 */
void GetKLeastNumbers_RedBlackTree(const vector<int> &data, multiset<int, std::greater<int>> &least_set, int k) {
    least_set.clear();
    if (k <= 0 || k > data.size())
        return;;
    for (const auto &item:data) {
        if (least_set.size() < k)
            least_set.insert(item);
        else {
            int max_in_set = *least_set.begin();
            if (max_in_set > item) {
                least_set.erase(least_set.begin());
                least_set.insert(item);
            }
        }
    }
}

// ====================方法2====================
typedef multiset<int, std::greater<int> > intSet;
typedef multiset<int, std::greater<int> >::iterator setIterator;
// ====================测试代码====================
void Test(char *testName, int *data, int n, int *expectedResult, int k) {
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    vector<int> vectorData;
    for (int i = 0; i < n; ++i)
        vectorData.push_back(data[i]);

    if (expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else {
        printf("Expected result: \n");
        for (int i = 0; i < k; ++i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result for solution1:\n");
    int *output = new int[k];
    GetKLeastNumbers_Partition(data, n, output, k);
    if (expectedResult != nullptr) {
        for (int i = 0; i < k; ++i)
            printf("%d\t", output[i]);
        printf("\n");
    }

    delete[] output;

    printf("Result for solution2:\n");
    intSet leastNumbers;
    GetKLeastNumbers_RedBlackTree(vectorData, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        printf("%d\t", *iter);
    printf("\n\n");
}

// k小于数组的长度
void Test1() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data)/sizeof(int), expected, sizeof(expected)/sizeof(int));
}

// k等于数组的长度
void Test2() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data)/sizeof(int), expected, sizeof(expected)/sizeof(int));
}

// k大于数组的长度
void Test3() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int *expected = nullptr;
    Test("Test3", data, sizeof(data)/sizeof(int), expected, 10);
}

// k等于1
void Test4() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data)/sizeof(int), expected, sizeof(expected)/sizeof(int));
}

// k等于0
void Test5() {
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int *expected = nullptr;
    Test("Test5", data, sizeof(data)/sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6() {
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data)/sizeof(int), expected, sizeof(expected)/sizeof(int));
}

// 输入空指针
void Test7() {
    int *expected = nullptr;
    Test("Test7", nullptr, 0, expected, 0);
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
    test40::run();

    return 0;
}

