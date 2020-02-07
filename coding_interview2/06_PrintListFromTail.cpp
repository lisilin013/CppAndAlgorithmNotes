//
// Created by Silin Li on 11:33 01/30/2020.
// 
#include "List.h"

namespace test6{

void run() {
    Algorithm::List<int> list;
    for (size_t i = 0; i < 10; ++i) {
        list.insertByPose(i, i);
    }
    list.traversal();
    list.traversalFromEndToStart();
}

}


int main(int argc, char **argv) {
    test6::run();
    return 0;
}

