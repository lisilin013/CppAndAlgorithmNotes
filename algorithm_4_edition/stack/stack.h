//
// Created by nrsl on 19-9-24.
//
#ifndef ALGORITHM_CPP_STACK_H
#define ALGORITHM_CPP_STACK_H

#include <iostream>
#include <cassert>
#include <algorithm>

namespace algorithm_cpp{

// 使用预分配内存构建，内存不够时，按照2倍扩展
template<typename T>
class Stack {
public:
    Stack() {
        top_ = 0;
        size_ = 100;//预分配内存
        data_ = new T[size_];
    }

    ~Stack() {
        delete[] data_;
    }

    //--------------------------------------
    // 常用操作，养成使用assert的好习惯
    //--------------------------------------
    T top() {
        assert(top_ > 0);
        return data_[top_ - 1];
    }


    void push(const T &d) {
        // 内存不够的时候，放大倍数扩展内存
        if (top_ >= size_) {
            T *tmp = data_;
            size_ *= 2;
            data_ = new T[size_];
            for (int i = 0; i < top_; ++i)
                data_[i] = tmp[i];
        }

        // push item
        data_[top_++] = d;
    }


    void pop() {
        assert(top_ > 0);
        top_--;
    }

    void print() {
        for (int i = 0; i < top_; ++i) {
            std::cout << data_[i] << " ";
        }
        std::cout << std::endl;
    }

    size_t size() { return top_; }

    bool empty() { return top_ == 0; }

private:
    size_t top_;//0(init), 1 , ...
    size_t size_;
    T *data_;
};
}
#endif //ALGORITHM_CPP_STACK_H
