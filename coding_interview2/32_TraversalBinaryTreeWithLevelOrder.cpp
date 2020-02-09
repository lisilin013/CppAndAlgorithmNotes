//
// Created by Silin Li on 17:11 02/08/2020.
// 

#include "BinaryTree.h"

using namespace std;

namespace test32{
using namespace Algorithm;
using BinaryTreeNode = Algorithm::BinaryTreeNode<int>;

void TraversalBinaryTreeWithLevelOrder(BinaryTreeNode *root) {
    if (!root)
        return;

    queue<BinaryTreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        auto node = nodes.front();
        cout << node->data << " ";
        nodes.pop();


        if (node->left)
            nodes.push(node->left);
        if (node->right)
            nodes.push(node->right);
    }
}

/**
 * @brief 按层打印二叉树，加回车
 */
void TraversalBinaryTreeWithLevelOrderByLine(BinaryTreeNode *root) {
    if (!root)
        return;

    queue<BinaryTreeNode *> nodes;
    nodes.push(root);
    int level = 0;
    int to_be_print = 1;
    while (!nodes.empty()) {
        auto node = nodes.front();
        cout << node->data << " ";
        nodes.pop();

        if (node->left) {
            nodes.push(node->left);
            ++level;
        }
        if (node->right) {
            nodes.push(node->right);
            ++level;
        }

        --to_be_print;
        if (to_be_print == 0) {
            cout << endl;
            to_be_print = level;
            level = 0;
        }

    }
}
/**
 * @brief z形式遍历二叉树
 */
void TraversalBinaryTreeWithLevelOrderByZFormat(BinaryTreeNode *root) {
    if (!root)
        return;

    stack<BinaryTreeNode *> nodes1, nodes2;
    nodes1.push(root);
    while (!nodes1.empty() || !nodes2.empty()) {
        // push to stack1 from left to right
        if (!nodes1.empty() && nodes2.empty()) {
            while (!nodes1.empty()) {
                auto node = nodes1.top();
                cout << node->data << " ";
                nodes1.pop();

                if (node->left)//left is firtst
                    nodes2.push(node->left);
                if (node->right)
                    nodes2.push(node->right);
            }
        }
        cout << endl;

        // push to stack2 from right to left
        if (nodes1.empty() && !nodes2.empty()) {
            while (!nodes2.empty()) {
                auto node = nodes2.top();
                cout << node->data << " ";
                nodes2.pop();

                if (node->right) //right is first
                    nodes1.push(node->right);
                if (node->left)
                    nodes1.push(node->left);
            }
        }
        cout << endl;
    }
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
void Test(char *testName, BinaryTreeNode *pRoot) {
    if (testName != nullptr)
        printf("%s begins: \n", testName);

    printf("The nodes from top to bottom, from left to right are: \n");
    TraversalBinaryTreeWithLevelOrder(pRoot);

    printf("\n");
    TraversalBinaryTreeWithLevelOrderByZFormat(pRoot);

    printf("\n\n");
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

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4() {
    BinaryTreeNode *pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyTree(pNode1);
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
    test32::run();
    return 0;
}

