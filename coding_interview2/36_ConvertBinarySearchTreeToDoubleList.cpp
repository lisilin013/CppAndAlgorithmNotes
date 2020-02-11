//
// Created by Silin Li on 21:35 02/11/2020.
// 

#include <iostream>
#include "BinaryTree.h"

using namespace std;

namespace test36{
using BinaryTreeNode = Algorithm::BinaryTreeNode<int>;
using namespace Algorithm;
/**
 * @brief
 * @param root
 * @param head : must be input by reference
 */
void ConvertBinarySearchTreeToDoubleListCore(BinaryTreeNode *root, BinaryTreeNode *&head) {
    // check
    if (!root)
        return;

    // 逆中序遍历
    // 使用right-->parent-->left的遍历顺序，这样得到的直接就是head
    // right
    BinaryTreeNode *node = root;
    if (node->right)
        ConvertBinarySearchTreeToDoubleListCore(root->right, head);

    // parent : do convert
    node->right = head;
    if (head)
        head->left = node;
    head = node;

    // left
    if (node->left)
        ConvertBinarySearchTreeToDoubleListCore(root->left, head);
}

BinaryTreeNode *ConvertBinarySearchTreeToDoubleList(BinaryTreeNode *root) {
    BinaryTreeNode *head = nullptr;
    ConvertBinarySearchTreeToDoubleListCore(root, head);
    return head;
}


// ====================辅助测试代码====================
BinaryTreeNode *CreateBinaryTreeNode(double dbValue) {
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->data = dbValue;
    pNode->left = nullptr;
    pNode->right = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight) {
    if (pParent != nullptr) {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void DestroyTree(BinaryTreeNode *pRoot) {
    if (pRoot != nullptr) {
        BinaryTreeNode *pLeft = pRoot->left;
        BinaryTreeNode *pRight = pRoot->right;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}


// ====================测试代码====================
void PrintDoubleLinkedList(BinaryTreeNode *pHeadOfList) {
    BinaryTreeNode *pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while (pNode != nullptr) {
        printf("%d\t", pNode->data);

        if (pNode->right == nullptr)
            break;
        pNode = pNode->right;
    }

    printf("\nThe nodes from right to left are:\n");
    while (pNode != nullptr) {
        printf("%d\t", pNode->data);

        if (pNode->left == nullptr)
            break;
        pNode = pNode->left;
    }

    printf("\n");
}

void DestroyList(BinaryTreeNode *pHeadOfList) {
    BinaryTreeNode *pNode = pHeadOfList;
    while (pNode != nullptr) {
        BinaryTreeNode *pNext = pNode->right;

        delete pNode;
        pNode = pNext;
    }
}

void Test(char *testName, BinaryTreeNode *pRootOfTree) {
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    TraversalInOrder(pRootOfTree);

    BinaryTreeNode *pHeadOfList = ConvertBinarySearchTreeToDoubleList(pRootOfTree);

    PrintDoubleLinkedList(pHeadOfList);
    printf("\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1() {
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode *pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyList(pNode4);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2() {
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyList(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyList(pNode1);
}

// 树中只有1个结点
void Test4() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyList(pNode1);
}

// 树中没有结点
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
    test36::run();
    return 0;
}

