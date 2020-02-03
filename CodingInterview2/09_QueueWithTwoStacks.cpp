//
// Created by Silin Li on 07:23 02/03/2020.
// 

#include <iostream>
#include <cassert>
#include <queue>
#include <stack>

using namespace std;
namespace test9{
template<typename T>
class QueueWithTwoStacks {
public:
    void push(const T &data) {
        s1.push(data);
    }
    void pop() {
        // check empty
        if (isEmpty()) {
            cout << "empty, cannot pop" << endl;
            return;
        }

        // 如果stack2空了，就把stack1上的元素放进2中
        // 2中的是最前面的
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    T top() {
        if (isEmpty()) {
            cout << "empty, has no top" << endl;
            return 0;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    size_t size() {
        return s1.size() + s2.size();
    }

    bool isEmpty() const { return s1.empty() && s2.empty(); }
private:
    stack<T> s1;
    stack<T> s2;
};

void run() {
    QueueWithTwoStacks<int> q;
    for (int i = 0; i < 10; ++i) {
        q.push(i);
    }

    cout << "size: " << q.size() << endl;
    cout << "top: " << q.top() << endl;

    for (int j = 0; j < 10; ++j) {
        if (!q.isEmpty())
        {
            cout << "-----------------\n";
            cout << "size: " << q.size() << endl;
            cout << "top: " << q.top() << endl;
            q.pop();
        }
    }

}
}

int main(int argc, char **argv) {
    test9::run();
    return 0;
}


