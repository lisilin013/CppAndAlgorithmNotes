//
// Created by Silin Li on 23:58 02/07/2020.
// 

#include "List.h"

using namespace std;

namespace test25{
using ListNode = Algorithm::ListNode<int>;
using List = Algorithm::List<int>;
using namespace Algorithm;

/**
 * @brief 小数在前，大数在后
 * @param head1
 * @param head2
 * @return
 */
ListNode *MergeTwoSortedLists(ListNode *head1, ListNode *head2) {
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    // head1 and head2 are all true
    // using recursive mode is very easy!
    ListNode *merge_head = nullptr;
    if (head1->data > head2->data) {
        merge_head = head2;
        merge_head->next = MergeTwoSortedLists(head1, head2->next);
    }
    else {
        merge_head = head1;
        merge_head->next = MergeTwoSortedLists(head1->next, head2);
    }
    return merge_head;
}

// ====================测试代码====================
ListNode *Test(char *testName, ListNode *pHead1, ListNode *pHead2) {
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode *pMergedHead = MergeTwoSortedLists(pHead1, pHead2);
    PrintList(pMergedHead);

    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

    DestroyList(pMergedHead);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
    ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
}

void run() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
}
}


int main(int argc, char **argv) {
    test25::run();
    return 0;
}

