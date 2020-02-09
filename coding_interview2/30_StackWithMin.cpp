//
// Created by Silin Li on 16:16 02/08/2020.
// 

#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

namespace test30{

/**
 * @brief 操作全部为O(1)
 */
template<typename T>
class StackWithMin {
public:
    size_t size() const { return data_stack_.size(); }
    bool empty() const { return size() == 0; }
    T top() const {
        assert(!empty());
        return data_stack_.top();
    }
    T min() const {
        assert(!empty());
        return min_stack_.top();
    }

    void push(const T &data) {
        data_stack_.push(data);
        if (min_stack_.empty() || min_stack_.top() > data) {
            min_stack_.push(data);
        }
        else {
            min_stack_.push(min_stack_.top());
        }
    }

    void pop() {
        assert(!empty());
        data_stack_.pop();
        min_stack_.pop();
    }

private:
    stack<T> data_stack_;
    stack<T> min_stack_;
};


void Test(const char *testName, const StackWithMin<int> &stack, int expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void run() {
    StackWithMin<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);
}

}

int main(int argc, char **argv) {
    test30::run();
    return 0;
}

