//
// Created by nrsl on 19-9-24.
//

#ifndef ALGORITHM_CPP_QUEUE_H
#define ALGORITHM_CPP_QUEUE_H
#include <cassert>
#include <iostream>
namespace algorithm_cpp{


template<typename T>
struct QueueNode {
    QueueNode(const T &d) {
        data = d;
    }

    T data;
    QueueNode *next;
};

// FIFO
template<typename T>
class Queue {
    using Ptr = QueueNode<T> *;
public:
    Queue() {
        front_ = back_ = nullptr;
        size_ = 0;
    }

    ~Queue() {
        while (!empty())
            pop();
    }


    // push in the back of queue
    void push(const T &d) {
        Ptr in_node = new QueueNode<T>(d);
        if (empty()) {
            front_ = back_ = in_node;
        }
        else {
            Ptr cur = back_;
            cur->next = in_node;
            back_ = in_node;
        }
        size_++;
    }

    // pop front of queue
    T pop() {
        assert(size_ > 0);
        T data = front_->data;

        Ptr cur = front_;
        front_ = cur->next;
        delete cur;
        size_--;

        return data;
    }

    bool empty() { return size_ == 0; }

    size_t size() { return size_; }

    void print() {
        std::cout<<"data: ";
        Ptr cur = front_;
        for (int i = 0; i < size_; ++i) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;

        std::cout << "size: " << size() << std::endl;
    }

private:
    int size_;
    Ptr front_;
    Ptr back_;
};
}
#endif //ALGORITHM_CPP_QUEUE_H
