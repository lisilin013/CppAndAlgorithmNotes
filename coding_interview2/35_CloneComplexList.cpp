//
// Created by Silin Li on 22:52 02/09/2020.
// 

#include <iostream>
#include <unordered_map>
using namespace std;

namespace test35{
struct ComplexListNode {
    explicit ComplexListNode(const int &d = 0) : data(d), next(nullptr), sibling(nullptr) {}
    int data;
    ComplexListNode *next;
    ComplexListNode *sibling; // point to any other node in list
};


//=================================
// auxiliary code
//=================================
void BuildNodes(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode *pSibling) {
    if (pNode != nullptr) {
        pNode->next = pNext;
        pNode->sibling = pSibling;
    }
}

void PrintList(ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    while (pNode != nullptr) {
        printf("%d ", pNode->data);

        if (pNode->sibling != nullptr)
            printf("%d ", pNode->sibling->data);
//        else
//            printf("This node does not have a sibling.\n");
        pNode = pNode->next;
    }
    printf("\n");

}

ComplexListNode *CreateNode(int nValue) {
    return new ComplexListNode(nValue);
}


/**
 * @brief using hash table <N, N'>
 * 空间复杂度O(N)，时间复杂度O(N)
 * @return cloned
 */
ComplexListNode *CloneComplexList_hash(ComplexListNode *head) {
    if (!head)
        return nullptr;

    // 1. clone the node
    unordered_map<ComplexListNode *, ComplexListNode *> nodes_map;
    ComplexListNode *cur_node = head;
    ComplexListNode *clone_node_head = CreateNode(cur_node->data);
    ComplexListNode *clone_cur_node = clone_node_head;
    nodes_map[cur_node] = clone_node_head;//<N, N'>

    while (cur_node->next) {
        clone_cur_node->next = CreateNode(cur_node->next->data);
        nodes_map[cur_node->next] = clone_cur_node->next;//<N, N'>

        cur_node = cur_node->next;
        clone_cur_node = clone_cur_node->next;
    }

    // 2. connect list nodes
    cur_node = head;
    while (cur_node) {
        if (cur_node->sibling) {// when this node has a sibling
            if (nodes_map.find(cur_node) != nodes_map.end()) {// in fact, this condition is redundant
                // N'          <==> N
                // N'->sibling <==> N->sibling)
                nodes_map[cur_node]->sibling = nodes_map[cur_node->sibling];
            }
            else {
                cerr << "error clone!\n";
                return nullptr;
            }
        }

        cur_node = cur_node->next;
    }

    return clone_node_head;
}


// ====================测试代码====================
void Test(const char *testName, ComplexListNode *pHead) {
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode *pClonedHead = CloneComplexList_hash(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
    printf("\n");
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1() {
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2() {
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3() {
    ComplexListNode *pNode1 = CreateNode(1);
    ComplexListNode *pNode2 = CreateNode(2);
    ComplexListNode *pNode3 = CreateNode(3);
    ComplexListNode *pNode4 = CreateNode(4);
    ComplexListNode *pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4() {
    ComplexListNode *pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5() {
    Test("Test5", nullptr);
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
    test35::run();
    return 0;
}

