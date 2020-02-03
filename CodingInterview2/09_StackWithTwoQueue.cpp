//
// Created by Silin Li on 07:56 02/03/2020.
// 

#include <iostream>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

namespace test9{

/**
 * q1: < 1 2 4 5
 * q2: <
 */
template<typename T>
class StackWithTwoQueue {
public:
    void push(const T &d) {
        if (isEmpty() || (!q1.empty() && q2.empty())) {
            q1.push(d);
        }
        else if (q1.empty() && !q2.empty()) {
            q2.push(d);
        }
        else {
            cout << "Push Wrong Operation!" << endl;
        }
    }

    void pop() {
        assert(!isEmpty());

        if (!q1.empty() && q2.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
        else if (q1.empty() && !q2.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
        else {
            cout << "Pop Wrong Operation!" << endl;
        }
    }

    T top() {
        assert(!isEmpty());

        if (!q1.empty() && q2.empty()) {
            return q1.back();
        }
        else if (q1.empty() && !q2.empty()) {
            return q2.back();
        }
        else {
            cout << "Top Wrong Operation!" << endl;
        }
    }

    size_t size() const {
        return q1.size() + q2.size();
    }

    bool isEmpty() const {
        return q1.empty() && q2.empty();
    }
private:
    queue<T> q1;
    queue<T> q2;
};

void run() {
    StackWithTwoQueue<int> s;
    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }

    cout << "size: " << s.size() << endl;
    cout << "top: " << s.top() << endl;

    for (int j = 0; j < 10; ++j) {
        if (!s.isEmpty()) {
            cout << "-----------------\n";
            cout << "size: " << s.size() << endl;
            cout << "top: " << s.top() << endl;
            s.pop();
        }

    }

}
}

int main(int argc, char **argv) {
    test9::run();
    return 0;
}

