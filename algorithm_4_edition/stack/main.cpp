//
// Created by nrsl on 19-9-24.
//

#include "stack.h"

using namespace algorithm_cpp;
int main(int argc, char**argv)
{
    Stack<int> stack;
    for (int i = 0; i < 2; ++i) {
        stack.push(i);
    }

    stack.print();

    stack.pop();
    stack.pop();
    stack.pop();

    stack.print();
    return 0;
}
