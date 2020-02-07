//
// Created by Silin Li on 18:47 02/07/2020.
// 

#include <iostream>
#include "List.h"

using namespace std;

namespace test23{
using ListNode = Algorithm::ListNode<int>;
using List = Algorithm::List<int>;
using namespace Algorithm;

ListNode *FindEntryNodeOfLoopInList(ListNode *head) {
    if (!head)
        return nullptr;

    // 1. make sure whether there is a loop in the list
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
            break;
    }

    // there is no loop in the list
    if (fast != slow && fast == nullptr)
        return nullptr;

    // 2. count the number of nodes in loop
    // now, fast and slow are all in the loop already
    fast = fast->next;
    int cnt = 1;
    while (fast != slow) {
        fast = fast->next;
        ++cnt;
    }

    // 3. find the entry node of loop
    fast = head;
    slow = head;
    for (int i = 0; i < cnt; ++i) {
        fast = fast->next;
    }

    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}


// ==================== Test Code ====================
void Test(char *testName, ListNode *pHead, ListNode *entryNode) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (FindEntryNodeOfLoopInList(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


// A list has a node, without a loop
void Test1() {
    ListNode *pNode1 = CreateListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2() {
    ListNode *pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop
void Test3() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
void Test4() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
void Test5() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop
void Test6() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7() {
    Test("Test7", nullptr, nullptr);
}

void run() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

}
}


int main(int argc, char **argv) {
    test23::run();
    return 0;
}

