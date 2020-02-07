//
// Created by Silin Li on 18:09 02/07/2020.
// 

#include <iostream>
#include "List.h"

using namespace std;

namespace test22{
using ListNode = Algorithm::ListNode<int>;
using List = Algorithm::List<int>;

/**
 * @brief: use two ptr
 * @param head: first node of the list
 * @param k>=1
 */
ListNode *FindMidNodeInList(ListNode *head, size_t k) {
    if (head == nullptr || k == 0)
        return nullptr;

    ListNode *front = head;
    ListNode *back = head;

    // make sure k is in the range of list length
    while (k >= 1 && front) {
        front = front->next;
        --k;
    }

    // list is too short
    if (k >= 1 && front == nullptr)
        return nullptr;

    while (front) {
        front = front->next;
        back = back->next;
    }
    return back;

}


// ====================测试代码====================
void PrintListNode(ListNode *node) {
    if (node)
        cout << node->data << endl;
    else
        cout << "nullptr" << endl;
}


void run() {
    printf("=====Test1 starts:=====\n");
    List list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }

    ListNode *pNode;
    for (int j = 0; j <= 6; ++j) {
        pNode = FindMidNodeInList(list.getNodeByPose(0), j);
        PrintListNode(pNode);
    }

    pNode = FindMidNodeInList(list.getNodeByPose(0), 100);
    PrintListNode(pNode);
    pNode = FindMidNodeInList(nullptr, 100);
    PrintListNode(pNode);

}
}

int main(int argc, char **argv) {
    test22::run();
    return 0;
}

