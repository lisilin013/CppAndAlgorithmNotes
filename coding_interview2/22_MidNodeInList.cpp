//
// Created by Silin Li on 18:35 02/07/2020.
//

#include <iostream>
#include "List.h"

using namespace std;

namespace test22
{
using ListNode = Algorithm::ListNode<int>;
using List = Algorithm::List<int>;
using namespace Algorithm;
/**
 * @brief: use two ptr
 * @param head: first node of the list
 * @param k>=1
 */
ListNode *FindMidNodeInList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *front = head;
    ListNode *back = head;

    // front run 2 steps
    // back run 1 step
    while (front)
    {
        front = front->next;
        if (front)
        {
            front = front->next;
            back = back->next;
        }
    }

    return back;
}

// ====================测试代码====================

void run()
{
    printf("=====Test starts:=====\n");
    List list;
    for (int i = 0; i < 10; ++i)
    {
        list.push_back(i);
    }
    list.traversal();

    ListNode *pNode;
    pNode = FindMidNodeInList(list.getNodeByPose(0));
    PrintListNode(pNode);
}
} // namespace test22

int main(int argc, char **argv)
{
    test22::run();
    return 0;
}
