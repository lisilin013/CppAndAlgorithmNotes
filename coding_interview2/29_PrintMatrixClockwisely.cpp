//
// Created by Silin Li on 11:12 02/08/2020.
// 

#include <iostream>
using namespace std;

namespace test29{
void PrintNumber(int number) {
    printf("%d ", number);
}
/**
 * traversal by clockwise
 *
 * (start, start)---->(start,end_x)
 *  |                       |
 *  |                       |
 * (end_y, start)<----(end_y, end_x)
 */
void PrintMatrixInCircle(int **matrix, size_t cols, size_t rows, int start) {
    size_t end_x = cols - start - 1;
    size_t end_y = rows - start - 1;

    // from top-left to top-right
    // traversal by a row
    int row = start;
    int col = start;
    for (; col <= end_x; ++col) {
        PrintNumber(matrix[row][col]);
    }

    // from top-right to bottom-right
    // traversal by a col
    if (start < end_y) {//加上判断，安全保险
        row = start + 1;
        col = end_x;
        for (; row <= end_y; ++row) {
            PrintNumber(matrix[row][col]);
        }
    }

    // from bottom-right to bottom left
    // traversal by a row
    if (start < end_y && start < end_x) {
        row = end_y;
        col = end_x - 1;
        for (; col >= start; --col) {
            PrintNumber(matrix[row][col]);
        }
    }

    // from bottom-left to top-left
    // traversal by a col
    if (start < end_x && start < end_y - 1) {
        row = end_y - 1;
        col = start;
        for (; row > start; --row) {
            PrintNumber(matrix[row][col]);
        }
    }
}
void PrintMatrixClockwisely(int **matrix, size_t cols, int rows) {
    if (!matrix || cols == 0 || rows == 0)
        return;

    int start = 0;
    while (cols > 2*start && rows > 2*start) {
        PrintMatrixInCircle(matrix, cols, rows, start);
        ++start;
    }
    printf("\n");
}


// ====================测试代码====================
void Test(int columns, int rows) {
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if (columns < 1 || rows < 1)
        return;

    int **numbers = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        numbers[i] = new int[columns];
        for (int j = 0; j < columns; ++j) {
            numbers[i][j] = i*columns + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for (int i = 0; i < rows; ++i)
        delete[] (int *) numbers[i];

    delete[] numbers;
}

void run() {
    /*
    1
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);
}

}


int main(int argc, char **argv) {
    test29::run();
    return 0;
}

