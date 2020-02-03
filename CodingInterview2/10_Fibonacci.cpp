//
// Created by Silin Li on 09:19 02/03/2020.
// 

#include <iostream>
#include <cassert>
using namespace std;


namespace test10{

size_t Fibonacci(size_t n) {
    assert(n >= 0);
    size_t first = 0;
    size_t second = 1;
    if (n == 0)
        return first;
    else if (n == 1)
        return second;
    else {
        size_t sum = 0;
        while (n > 1) {
            sum = first + second;
            first = second;
            second = sum;
            --n;
        }
        return sum;
    }
}

void run() {
    for (int i = 0; i < 10; ++i) {
        cout << "Fibonacci(" << i << ") = " << Fibonacci(i) << endl;
    }
}
}


int main(int argc, char **argv) {
    test10::run();
    return 0;
}

