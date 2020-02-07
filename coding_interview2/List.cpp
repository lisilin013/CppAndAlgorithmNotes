//
// Created by Silin Li on 19:05 02/07/2020.
// 

#include "List.h"

namespace Algorithm{

ListNode<int> *CreateListNode(int value) {
    ListNode<int> *pNode = new ListNode<int>();
    pNode->data = value;
    pNode->next = nullptr;

    return pNode;
}

void ConnectListNodes(ListNode<int> *pCurrent, ListNode<int> *pNext) {
    if (pCurrent == nullptr) {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->next = pNext;
}

void PrintListNode(ListNode<int> *pNode) {
    if (pNode == nullptr) {
        printf("The node is nullptr\n");
    }
    else {
        printf("The key in node is %d.\n", pNode->data);
    }
}

void PrintList(ListNode<int> *pHead) {
    printf("PrintList starts.\n");

    ListNode<int> *pNode = pHead;
    while (pNode != nullptr) {
        printf("%d\t", pNode->data);
        pNode = pNode->next;
    }

    printf("\nPrintList ends.\n");
}

void DestroyList(ListNode<int> *pHead) {
    ListNode<int> *pNode = pHead;
    while (pNode != nullptr) {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

}

