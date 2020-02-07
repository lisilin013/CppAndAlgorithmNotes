//
// Created by Silin Li on 23:22 02/07/2020.
// 

#include "List.h"

using namespace std;

namespace test24{
using ListNode = Algorithm::ListNode<int>;
using List = Algorithm::List<int>;
using namespace Algorithm;

/**
 * @brief reverse a list using 3 pointers
 * @param head
 * @return new head after reverse list
 */
ListNode *ReverseList(ListNode *head) {
    if (!head)
        return nullptr;

    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *next = nullptr;
    while (cur) {
        // save next node
        next = cur->next;

        // reverse
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;// pre is the reverse_node
}

void run() {
    for (int i = 0; i <= 5; ++i) {
        List list;
        for (int j = 0; j < i; ++j) {
            list.push_back(j);
        }
        ListNode *reverse_head = ReverseList(list.head());
        PrintList(reverse_head);
    }
}
}


int main(int argc, char **argv) {
    test24::run();
    return 0;
}





