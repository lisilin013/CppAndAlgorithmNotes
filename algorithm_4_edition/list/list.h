//
// Created by nrsl on 19-9-23.
//

#ifndef ALGORITHM_CPP_LIST_H
#define ALGORITHM_CPP_LIST_H

#include <cstddef>
#include <memory>
#include <cassert>

namespace algorithm_cpp{

// double-direction link list
template<typename T>
struct ListNode {
    ListNode() = default;

    ListNode(const T &d) : data(d) {}

    T data;
    ListNode<T> *pre;
    ListNode<T> *next;
};

template<typename T>
class List {
    using Ptr=ListNode<T> *;
public:
    List() {
        front_ = nullptr;
        back_ = nullptr;
        size_ = 0;
    }

    ~List() {
        while (!empty())
            this->pop_back();
    }

    // ---------------------------------------
    // 插入删除操作
    // 插入到对应的位置
    // 0,1,2,3, ^ ,4,5
    // ---------------------------------------
    void insert(const T &data, size_t pose) {
        assert(pose >= 0 && pose <= size_);
        Ptr in_node = new ListNode<T>(data);

        // empty
        if (empty()) {
            back_ = front_ = in_node;
            front_->next = nullptr;
            front_->pre = nullptr;
            back_->next = nullptr;
            back_->pre = nullptr;
        }
        else {         // not empty 找到需要插入的位置cur
            if (pose == 0) {//插入的是头
                Ptr cur = front_;
                in_node->next = cur;
                cur->pre = in_node;
                front_ = in_node;
            }
            else if (pose == size_) {//插入尾
                Ptr cur = back_;
                cur->next = in_node;
                in_node->pre = cur;
                back_ = in_node;
            }
            else {//插入中间
                Ptr cur = front_;
                while (pose) {
                    cur = cur->next;
                    pose--;
                }
                Ptr tmp1 = cur->pre;
                Ptr tmp2 = cur;

                tmp1->next = in_node;
                in_node->pre = tmp1;
                tmp2->pre = in_node;
                in_node->next = tmp2;
            }
        }

        // update list size
        size_++;
    }

    void erase(size_t pose) {
        assert(pose >= 0 && pose <= size_ - 1);

        // 不为空，分几种情况
        if (size_ == 1) {
            Ptr cur = front_;
            front_ = back_ = nullptr;
            delete cur;
        }
        else if (pose == 0) {
            Ptr cur = front_;
            front_ = cur->next;
            front_->pre = nullptr;
            delete cur;
        }
        else if (pose == size_ - 1) {
            Ptr cur = back_;
            back_ = cur->pre;
            back_->next = nullptr;
            delete cur;
        }
        else {
            Ptr cur = front_;
            while (pose) {
                cur = cur->next;
                pose--;
            }
            Ptr tmp1 = cur->pre;
            Ptr tmp2 = cur->next;
            tmp1->next = tmp2;
            tmp2->pre = tmp1;
            delete cur;
        }

        // update list size
        size_--;
    }


    //---------------------------------------------
    // 下标访问
    //---------------------------------------------
    T operator[](size_t pose) {
        assert(pose >= 0 && pose <= size_ - 1);
        Ptr cur;
        while (pose) {
            cur = cur->next;
            pose--;
        }
        return cur->data;
    }

    T at(size_t pose) {
        assert(pose >= 0 && pose <= size_ - 1);
        Ptr cur;
        while (pose) {
            cur = cur->next;
            pose--;
        }
        return cur->data;
    }

    //---------------------------------------------
    // 其他常用接口函数
    //---------------------------------------------
    void push_front(const T &data) { insert(data, 0); }

    void push_back(const T &data) { insert(data, size_); }

    void pop_front() { erase(0); }

    void pop_back() { erase(size_ - 1); }

    T front() {
        assert(size_ > 0);
        return front_->data;
    }

    T back() {
        assert(size_ > 0);
        return back_->data;
    }

    size_t size() { return size_; }

    bool empty() { return size_ == 0; }

    void print() {
        size_t pose = size_;
        Ptr cur = front_;
        while (pose) {
            std::cout << cur->data << " ";
            cur = cur->next;
            pose--;
        }
        std::cout << std::endl;
    }

private:
    Ptr front_;
    Ptr back_;
    size_t size_;
};
}


#endif //ALGORITHM_CPP_LIST_H
