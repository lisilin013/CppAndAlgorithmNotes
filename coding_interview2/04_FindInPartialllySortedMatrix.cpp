//
// Created by Silin Li on 16:05 01/26/2020.
// 

#include <iostream>
#include <cassert>

using namespace std;

namespace test4{


/**
 * @brief using iterative
 * @param matrix 
 * @param rows 
 * @param cols 
 * @return 
 */
bool Find(int *matrix, int rows, int cols, int num) {
    // check inputs
    assert(matrix && rows > 0 || cols > 0);

    // output
    bool found = false;
    // traverse from Right-Top corner
    int row = 0;
    int col = cols - 1;
    while (row < rows && col > 0) {// end condition: still not found until traverse to the Left-Down corner
        int cur_num = matrix[row*cols + col];
        if (cur_num == num) {
            cout << "(row, col) = (" << row << ", " << col << ")" << endl;
            found = true;
            break;
        }
        else if (cur_num > num) {
            --col;
        }
        else {
            ++row;
        }

    }

    return found;
}

void run() {
    int matrix[16] = {1, 2, 8, 9,
                      2, 4, 9, 12,
                      4, 7, 10, 13,
                      6, 8, 9, 14};
    Find(matrix, 4, 4, 8);
}
}


int main(int argc, char **argv) {
    test4::run();
    return 0;
}

