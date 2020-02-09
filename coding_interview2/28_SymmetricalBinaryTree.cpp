//
// Created by Silin Li on 10:58 02/08/2020.
// 


#include "BinaryTree.h"
#include <stack>
#include <queue>

using namespace std;

namespace test28{
using namespace Algorithm;
using BinaryTreeNode = Algorithm::BinaryTreeNode<int>;
using BinaryTree = Algorithm::BinaryTree<int>;

/**
 * @brief root1 and root2 are mirror
 */
bool IsSymmetricalBinaryTree(BinaryTreeNode *root1, BinaryTreeNode *root2) {
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)//其中一个为null，一个不为null
        return false;
    if (root1->data != root2->data)
        return false;

    // root相同
    return IsSymmetricalBinaryTree(root1->left, root2->right) &&
           IsSymmetricalBinaryTree(root1->right, root2->left);
}

bool IsSymmetricalBinaryTree(BinaryTreeNode *root) {
    if (!root)//二叉树为空，是否算mirror，和面试官讨论决定
        return false;

    return IsSymmetricalBinaryTree(root->left, root->right);
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
void Test(char *testName, BinaryTreeNode *pRoot, bool expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (IsSymmetricalBinaryTree(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      6
//       5 7    7 5
void Test1() {
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode52 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, pNode52);

    Test("Test1", pNode8, true);

    DestroyTree(pNode8);
}

//            8
//        6      9
//       5 7    7 5
void Test2() {
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode *pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode52 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode61, pNode9);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode9, pNode72, pNode52);

    Test("Test2", pNode8, false);

    DestroyTree(pNode8);
}

//            8
//        6      6
//       5 7    7
void Test3() {
    BinaryTreeNode *pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode *pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode *pNode72 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, nullptr);

    Test("Test3", pNode8, false);

    DestroyTree(pNode8);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
void Test4() {
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode21 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode11 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, nullptr, pNode42);
    ConnectTreeNodes(pNode41, pNode21, nullptr);
    ConnectTreeNodes(pNode42, nullptr, pNode22);
    ConnectTreeNodes(pNode21, pNode11, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode12);

    Test("Test4", pNode5, true);

    DestroyTree(pNode5);
}


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
void Test5() {
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode *pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode11 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, nullptr, pNode42);
    ConnectTreeNodes(pNode41, pNode6, nullptr);
    ConnectTreeNodes(pNode42, nullptr, pNode22);
    ConnectTreeNodes(pNode6, pNode11, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode12);

    Test("Test5", pNode5, false);

    DestroyTree(pNode5);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
void Test6() {
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode21 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, nullptr, pNode42);
    ConnectTreeNodes(pNode41, pNode21, nullptr);
    ConnectTreeNodes(pNode42, nullptr, pNode22);
    ConnectTreeNodes(pNode21, nullptr, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode12);

    Test("Test6", pNode5, false);

    DestroyTree(pNode5);
}

// 只有一个结点
void Test7() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    Test("Test7", pNode1, true);

    DestroyTree(pNode1);
}

// 没有结点
void Test8() {
    Test("Test8", nullptr, true);
}

// 所有结点都有相同的值，树对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
void Test9() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode21 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode22 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode31 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode32 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode41 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode42 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, nullptr, pNode42);
    ConnectTreeNodes(pNode41, nullptr, nullptr);
    ConnectTreeNodes(pNode42, nullptr, nullptr);

    Test("Test9", pNode1, true);

    DestroyTree(pNode1);
}

// 所有结点都有相同的值，树不对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
void Test10() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode21 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode22 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode31 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode32 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode41 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode42 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, nullptr);
    ConnectTreeNodes(pNode22, nullptr, pNode32);
    ConnectTreeNodes(pNode31, pNode41, nullptr);
    ConnectTreeNodes(pNode32, pNode42, nullptr);
    ConnectTreeNodes(pNode41, nullptr, nullptr);
    ConnectTreeNodes(pNode42, nullptr, nullptr);

    Test("Test10", pNode1, false);

    DestroyTree(pNode1);
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
    Test9();
    Test10();

}
}


int main(int argc, char **argv) {
    test28::run();
    return 0;
}

