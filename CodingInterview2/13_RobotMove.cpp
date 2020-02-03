//
// Created by Silin Li on 20:02 02/03/2020.
// 

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

namespace test13{
int GetDigitSum(int number) {
    assert(number >= 0);
    int sum = 0;
    while (number) {
        sum += number%10;//累加低位
        number /= 10;
    }
    return sum;
}

int MovingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited) {
    assert(threshold >= 0 && rows > 0 && cols > 0);
    int count = 0;
    if (row >= 0 && row < rows && col >= 0 && col < cols &&
        (GetDigitSum(col) + GetDigitSum(row) <= threshold) && !visited[row*cols + col]) {
        visited[row*cols + col] = true;
        ++count; // 加上本节点
        count += MovingCountCore(threshold, rows, cols, row, col + 1, visited) +
                 MovingCountCore(threshold, rows, cols, row, col - 1, visited) +
                 MovingCountCore(threshold, rows, cols, row + 1, col, visited) +
                 MovingCountCore(threshold, rows, cols, row - 1, col, visited);
    }
    return count;

}
int MovingCount(int threshold, int rows, int cols) {
    assert(threshold >= 0 && rows > 0 && cols > 0);
    bool *visited = new bool[rows*cols];
    std::fill(visited, visited + rows*cols, false);

    int count = MovingCountCore(threshold, rows, cols, 0, 0, visited);

    delete[] visited;
    return count;
}



// ====================测试代码====================
void test(char *testName, int threshold, int rows, int cols, int expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (MovingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 方格多行多列
void test1() {
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2() {
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3() {
    test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4() {
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5() {
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6() {
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7() {
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8() {
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9() {
    test("Test9", -10, 10, 10, 0);
}
void run() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
}
}

int main(int argc, char **argv) {
    test13::run();
    return 0;
}

