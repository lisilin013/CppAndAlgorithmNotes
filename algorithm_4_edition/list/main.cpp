//
// Created by nrsl on 19-9-23.
//
#include <iostream>
#include <vector>
#include "list.h"
using namespace std;
using algorithm_cpp::List;

int main(int argc, char **argv) {
    List<int> list;
    for (int i = 0; i < 10; ++i) {
        list.insert(i, i);
    }
    list.print();

    list.push_front(-1);
    list.push_back(-1);
    list.print();

    list.pop_back();
    list.pop_front();
    list.print();
}

