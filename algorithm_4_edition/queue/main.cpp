//
// Created by nrsl on 19-9-24.
//

#include "queue.h"

using namespace algorithm_cpp;

int main() {
    Queue<int> queue;
    for (int i = 0; i < 10; ++i) {
        queue.push(i);
    }
    queue.print();

    return 0;
}

