//
// Created by Silin Li on 23:27 02/03/2020.
// 

#include <iostream>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

namespace test17{

void PrintBigNumber(char *number) {
    int len = strlen(number);
    bool is_beginning = true;
    for (int i = 0; i < len; ++i) {
        if (is_beginning && number[i] != '0')
            is_beginning = false;
        if (!is_beginning) {
            printf("%c", number[i]);//此处不能用cout
        }
    }
    printf(" ");
}

//-------------------------------------------------
// iteratively
//-------------------------------------------------
/**
 * @brief
 * @param number
 * @return return true when increment result is non-zero
 */
bool Increment(char *number) {
    int len = strlen(number);
    int n_takeover = 0;
    bool is_overflow = false;

    for (int i = len - 1; i >= 0; --i) {
        int sum = (number[i] - '0') + n_takeover;//handle takeover
        if (i == len - 1) {
            ++sum;//increment at the lowest bit
        }

        if (sum >= 10) {
            if (i == 0) {
                is_overflow = true;
            }
            else {
                n_takeover = 1;
                sum -= 10;
                number[i] = sum + '0';
            }
        }
        else {
            number[i] = sum + '0';
            break;
        }
    }

    return is_overflow;
}


void PrintOneToMaxOfNDigits(int n) {
    if (n <= 0) {
        return;
    }

    char *number = new char[n + 1];// notice '\0'
    std::fill(number, number + n, '0');
    number[n] = '\0';

    while (!Increment(number)) {
        PrintBigNumber(number);
    }

    delete[] number;
}

//-------------------------------------------------
// recursively
// 0~9的全排列
//-------------------------------------------------
void PrintOneToMaxOfNDigitsRecursivelyCore(char *number, int index) {
    if (index == strlen(number) - 1) {
        PrintBigNumber(number);
        return;
    }

    // set 0~9 for every bit
    for (int i = 0; i < 10; ++i) {
        number[index + 1] = i + '0';
        PrintOneToMaxOfNDigitsRecursivelyCore(number, index + 1);
    }
}


void PrintOneToMaxOfNDigitsRecursively(int n) {
    if (n <= 0)
        return;

    char *number = new char[n + 1];// notice '\0'
    std::fill(number, number + n, '0');
    number[n] = '\0';

    PrintOneToMaxOfNDigitsRecursivelyCore(number, -1);
    delete[] number;
}


void run() {
    PrintOneToMaxOfNDigitsRecursively(3);
}
}


int main(int argc, char **argv) {
    test17::run();
    return 0;
}


