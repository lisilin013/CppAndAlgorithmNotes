//
// Created by Silin Li on 09:53 01/09/2020.
// 
#include <iostream>
#include <string>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

namespace test12{

bool HasStringPathInMatrixCore(const char *matrix, int rows, int cols, int row, int col,
                               const char *str, int &path_len, bool *visited) {
    if (str[path_len] == '\0') {
        return true;
    }

    bool has_path = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[cols*row + col] == str[path_len] && !visited[cols*row + col]) {//字母相同且没有被访问过
        ++path_len;
        visited[row*cols + col] = true;
        has_path = HasStringPathInMatrixCore(matrix, rows, cols, row + 1, col, str, path_len, visited) ||
                   HasStringPathInMatrixCore(matrix, rows, cols, row - 1, col, str, path_len, visited) ||
                   HasStringPathInMatrixCore(matrix, rows, cols, row, col + 1, str, path_len, visited) ||
                   HasStringPathInMatrixCore(matrix, rows, cols, row, col - 1, str, path_len, visited);
        if (!has_path) {
            --path_len;
            visited[row*cols + col] = false;
        }
    }
    return has_path;
}
bool HasStringPathInMatrix(const char *matrix, int rows, int cols, const char *str) {
    assert(matrix && rows >= 0 && cols >= 0 && str);

    bool has_path = false;
    bool *visited = new bool[rows*cols];
//    std::fill(visited, visited + rows*cols, false);
    memset(visited, 0, rows*cols);
    int path_len = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (HasStringPathInMatrixCore(matrix, rows, cols, i, j, str, path_len, visited)) {
                // print the matrix and the path
                cout << "Find the str path in string matrix: " << endl;
                for (int ii = 0; ii < rows; ++ii) {
                    for (int jj = 0; jj < cols; ++jj) {
                        if (visited[ii*cols + jj])//why it is always false???
                        {
                            cout << matrix[ii*cols + jj] << "* ";
                        }
                        else {
                            cout << matrix[ii*cols + jj] << "  ";
                        }

                    }
                    cout << endl;
                }

                delete[]visited;
                return true;
            }
        }
    }

    delete[] visited;
    return false;
}


void run() {
    int rows = 3, cols = 4;
    string matrix_str = "abtgcfcsjdeh";
    string dest_str = "bfce";
    const char *matrix = matrix_str.c_str();
    const char *str = dest_str.c_str();
    HasStringPathInMatrix(matrix, rows, cols, str);
}
}

int main(int argc, char **argv) {
    test12::run();
    return 0;
}

