//
// Created by Silin Li on 11:30 01/30/2020.
// 

#ifndef CODINGINTERVIEW_LIST_H
#define CODINGINTERVIEW_LIST_H
#include <iostream>
#include <cassert>
namespace Algorithm{

template<typename T>
struct ListNode {
    explicit ListNode(const T &d) : data(d), next(nullptr) {}
    ListNode() : next(nullptr) {}
    T data;
    ListNode *next;
};

//-------------------------------
// only for test algorithm
//-------------------------------
ListNode<int> *CreateListNode(int value);
void ConnectListNodes(ListNode<int> *pCurrent, ListNode<int> *pNext);
void DestroyList(ListNode<int> *pHead);
void PrintListNode(ListNode<int> *pNode);
void PrintList(ListNode<int> *pHead);

//---------------------------------------
// single list
//---------------------------------------
template<typename T>
class SingleList {
public:
    using NodeType = ListNode<T>;


    SingleList() : head_(new NodeType()) {}
    ~SingleList() {
        while (!isEmpty()) {
            pop_front();
        }
    }

    bool isEmpty() const {
        return !head_->next;
    }

    size_t size() const {
        size_t sz = 0;
        auto node = head_->next;
        while (node) {
            ++sz;
            node = node->next;
        }
        return sz;
    }
    //---------------------------------------------------------
    // insert
    //---------------------------------------------------------
    /**
     * @brief insert data at this pose
     * @param pose
     * @param data
     * @return
     */
    bool insertByPose(const size_t &pose, const T &data) {
        // check input
        assert(pose >= 0);

        NodeType *node_new = new NodeType(data);
        NodeType *cur_node = head_->next;// first node
        NodeType *pre_node = head_;
        size_t index = 0;
        while (cur_node) {
            if (index == pose) {
                pre_node->next = node_new;
                node_new->next = cur_node;
                return true;
            }

            ++index;
            pre_node = cur_node;
            cur_node = cur_node->next;
        }
        // add to the tail
        if (index == pose) {
            pre_node->next = node_new;
            return true;
        }

        // pose is too big
        std::cerr << "pose is too big!" << std::endl;
        return false;
    }

    //---------------------------------------------------------
    // erase
    //---------------------------------------------------------
    /**
     * @brief algorithm complex O(n)
     */
    bool eraseByPose(const size_t &pose) {
        // check input
        assert(pose >= 0);

        NodeType *pre_node = head_;
        NodeType *cur_node = head_->next;
        size_t index = 0;
        while (cur_node) {
            if (index == pose) {
                NodeType *node = cur_node;
                pre_node->next = cur_node->next;
                delete node;
                return true;
            }
            ++index;
            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        std::cerr << "erase by pose failed!" << std::endl;
        return false;
    }

    bool eraseByValue(const T &value) {
        NodeType *pre_node = head_;
        NodeType *cur_node = head_->next;
        size_t index = 0;
        while (cur_node) {
            if (cur_node->data == value) {
                NodeType *node = cur_node;
                pre_node->next = cur_node->next;
                delete node;
                return true;
            }
            ++index;
            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        std::cerr << "erase by value failed!" << std::endl;
        return false;
    }

    /**
     * @brief algorithm complex O(n)
     */
    bool eraseByNode(NodeType *node) {
        assert(node);

        NodeType *pre_node = head_;
        NodeType *cur_node = head_->next;
        while (cur_node) {
            if (cur_node == node) {
                NodeType *del_node = cur_node;
                pre_node->next = cur_node->next;
                delete del_node;
                return true;
            }
            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        std::cerr << "node address is not exist" << std::endl;
        return false;
    }

    /**
     * @brief algorithm complex O(1)
     */
    bool eraseByNodeAdvanced(NodeType *node) {
        assert(node);

        if (isEmpty()) {
            std::cerr << "list is empty" << std::endl;
            return false;
        }

        NodeType *pre_node = node;
        NodeType *cur_node = node->next;
        if (cur_node) {
            NodeType *next_node = cur_node->next;
            std::swap(pre_node->data, cur_node->data);
            pre_node->next = next_node;
            delete cur_node;
        }
        else {// node is the last node
            eraseByPose(size() - 1);
        }
        return true;
    }

    //---------------------------------------------------------
    // get node
    //---------------------------------------------------------
    NodeType *getNodeByPose(const size_t &pose) {
        assert(pose >= 0);

        size_t i = 0;
        NodeType *cur_node = head_->next;
        while (cur_node) {
            if (i == pose) {
                return cur_node;
            }
            ++i;
            cur_node = cur_node->next;
        }
        return nullptr;
    }

    NodeType *getNodeByValue(const T &vallue) {
        size_t i = 0;
        NodeType *cur_node = head_->next;
        while (cur_node) {
            if (cur_node->data == vallue) {
                return cur_node;
            }

            cur_node = cur_node->next;
        }
        return nullptr;
    }

    //----------------------------------------
    // interface
    //----------------------------------------
    bool push_back(const T &data) {
        insertByPose(size(), data);
    }

    NodeType pop_back() {

        eraseByPose(size() - 1);
    }
    bool push_front(const T &data) {
        insertByPose(0, data);
    }

    NodeType pop_front() {
        eraseByPose(size_t(0));
    }

    //----------------------------------------
    // traversal
    //----------------------------------------
    void traversal() {
        NodeType *node = head_->next;
        std::cout << "List size: " << size() << std::endl;
        while (node) {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    void traversalFromEndToStart() {
        if (isEmpty()) {
            return;
        }
        traversalFromEndToStartCore(head_->next);
        std::cout << std::endl;
    }


private:
    void traversalFromEndToStartCore(NodeType *node) {
        if (node->next) {
            traversalFromEndToStartCore(node->next);
        }
        std::cout << node->data << " ";
    }

    ListNode<T> *head_;// using a head_ to simplify coding
};

template<typename T>
using List=SingleList<T>;
}

#endif //CODINGINTERVIEW_LIST_H
