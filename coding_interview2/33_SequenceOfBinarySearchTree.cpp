//
// Created by Silin Li on 14:03 02/09/2020.
// 

#include "BinaryTree.h"

using namespace std;

namespace test33{
using namespace Algorithm;

using BinaryTreeNode = Algorithm::BinaryTreeNode<int>;

bool VerifyPostOrderSequenceOfBinarySearchTree(int *sequence, int length) {
    if (!sequence || length <= 0)
        return false;

    // 1. get root node
    int root = sequence[length - 1];

    // 2. get left node sequence
    int end = length - 1;// 剔除最后一个root元素
    int left_end = 0;
    for (int i = 0; i < end; ++i) {
        if (sequence[i] < root)
            ++left_end;
        else
            break;
    }

    // 3. make sure left node sequence is illegal
    for (int j = left_end; j < end; ++j) {
        if (sequence[j] > root)
            continue;
        else
            return false;
    }

    // 4. recursive
    bool left = true, right = true;
    if (left_end > 0)
        left = VerifyPostOrderSequenceOfBinarySearchTree(sequence, left_end);
    if (end > left_end)
        right = VerifyPostOrderSequenceOfBinarySearchTree(sequence + left_end, end - left_end);
    return left && right;
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
void Test(const char *testName, int sequence[], int length, bool expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (VerifyPostOrderSequenceOfBinarySearchTree(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1() {
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2() {
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
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
void Test3() {
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
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
void Test4() {
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// 树中只有1个结点
void Test5() {
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6() {
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7() {
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8() {
    Test("Test8", nullptr, 0, false);
}


void run() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
}
}


int main(int argc, char **argv) {
    test33::run();
    return 0;
}


