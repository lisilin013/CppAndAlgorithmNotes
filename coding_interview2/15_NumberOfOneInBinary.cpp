//
// Created by Silin Li on 16:13 01/10/2020.
// 
#include <iostream>
using namespace std;

namespace test15{
// << 最右边补0
// >> 如果是正数，最左边补0；如果是负数，最左边补1

/**
 * O(32)做法，1，不断<<，绝对不能用>>,就是因为负数的原因
 * @param n
 * @return
 */
int NumOf1InBinary(const int &n) {
    int cnt = 0;
    unsigned int flag = 1;
    // 当32位遍历结束，flag会变为0，循环终止
    while (flag) {
        if (flag & n) {
            ++cnt;
        }
        flag <<= 1;

    }

    return cnt;
}


/**
 * O(1)时间，更高效
 * 主要思想：把一个整数-1,，再和原来的数求&就会把原来整数最右边的1变为0，也就是会消掉一个1
 * @param n
 * @return
 */
int NumOf1InBinaryAdvanced(const int &n) {
    int num = n;
    int cnt = 0;
    while (num) {
        num = num & (num - 1);
        ++cnt;
    }

    return cnt;
}


void run() {
    for (int i = 0; i < 100; ++i) {
        cout << i << " has: " << NumOf1InBinary(i) << " ONE in binary format" << endl;
        cout << i << " has: " << NumOf1InBinaryAdvanced(i) << " ONE in binary format" << endl;
    }

}
}

int main(int argc, char **argv) {
    test15::run();
    return 0;
}

