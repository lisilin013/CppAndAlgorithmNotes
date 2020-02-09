//
// Created by Silin Li on 22:06 02/09/2020.
// 

#include "BinaryTree.h"

using namespace std;

namespace test34{
using namespace Algorithm;
using BinaryTreeNode = Algorithm::BinaryTreeNode<int>;
void FindSumPathInBinaryTree(BinaryTreeNode *root, int &expect_sum, vector<int> &path, int &current_sum) {
    // pre-order traversal
    current_sum += root->data;//路径的定义是从root-->leaf
    path.push_back(root->data);
    bool is_leaf = !root->left && !root->right;
    if (current_sum == expect_sum && is_leaf) {
        for (const auto &item:path) {
            printf("%d ", item);
        }
        printf("\n");
    }

    if (root->left)
        FindSumPathInBinaryTree(root->left, expect_sum, path, current_sum);
    if (root->right)
        FindSumPathInBinaryTree(root->right, expect_sum, path, current_sum);

    // 访问到叶节点才会到这里，下面就是访问父节点的右子节点
    path.pop_back();
    current_sum -= root->data;
}
void FindSumPathInBinaryTree(BinaryTreeNode *root, int expect_sum) {
    if (!root)
        return;

    vector<int> path;//push_back和pop_back类似stack的操作，但是访问可以更自由
    int current_sum = 0;
    FindSumPathInBinaryTree(root, expect_sum, path, current_sum);
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
void Test(char *testName, BinaryTreeNode *pRoot, int expectedSum) {
    if (testName != nullptr)
        printf("%s begins expected_sum=%d:\n", testName, expectedSum);

    FindSumPathInBinaryTree(pRoot, expectedSum);

    printf("\n");
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// 有两条路径上的结点和为22
void Test1() {
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22);

    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// 没有路径上的结点和为15
void Test2() {
    BinaryTreeNode *pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test("Test2", pNode10, 15);

    DestroyTree(pNode10);
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
// 有一条路径上面的结点和为15
void Test3() {
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    printf("One path should be found in Test3.\n");
    Test("Test3", pNode5, 15);

    DestroyTree(pNode5);
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
// 没有路径上面的结点和为16
void Test4() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    printf("No paths should be found in Test4.\n");
    Test("Test4", pNode1, 16);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test5() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test("Test5", pNode1, 1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test6() {
    printf("No paths should be found in Test6.\n");
    Test("Test6", nullptr, 0);
}
void run() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

}
}


int main(int argc, char **argv) {
    test34::run();
    return 0;
}

