//
// Created by Silin Li on 09:39 02/08/2020.
// 


#include "BinaryTree.h"
#include <stack>
#include <queue>

using namespace std;

namespace test27{
using namespace Algorithm;
using BinaryTreeNode = Algorithm::BinaryTreeNode<int>;
using BinaryTree = Algorithm::BinaryTree<int>;

void MirrorBinaryTreeRecursively(BinaryTreeNode *root) {
    if (!root)
        return;

    if (!root->left && !root->right)//是叶节点
        return;

    std::swap(root->left, root->right);
    if (root->left)
        MirrorBinaryTreeRecursively(root->left);
    if (root->right)
        MirrorBinaryTreeRecursively(root->right);
}


void MirrorBinaryTreeIteratively(BinaryTreeNode *root) {
    if (!root)
        return;

    // 此处使用queue或者stack都无所谓，因为和遍历顺序没有关系
    queue<BinaryTreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        BinaryTreeNode *node = nodes.front();
        nodes.pop();

        std::swap(node->left, node->right);
        if (node->left)
            nodes.push(node->left);
        if (node->right)
            nodes.push(node->right);
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
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test1() {
    printf("=====Test1 starts:=====\n");
    auto node8 = new BinaryTreeNode(8);
    auto node6 = new BinaryTreeNode(6);
    auto node10 = new BinaryTreeNode(10);
    auto node5 = new BinaryTreeNode(5);
    auto node7 = new BinaryTreeNode(7);
    auto node9 = new BinaryTreeNode(9);
    auto node11 = new BinaryTreeNode(11);
    node8->left = node6;
    node8->right = node10;
    node6->left = node5;
    node6->right = node7;
    node10->left = node9;
    node10->right = node11;
    BinaryTree tree;
    tree.setRoot(node8);
    TraversalInOrder(node8);


    printf("=====Test1: MirrorBinaryTreeRecursively=====\n");
    MirrorBinaryTreeRecursively(tree.getRoot());
    tree.traversalInOrder();

    printf("=====Test1: MirrorBinaryTreeIteratively=====\n");
    MirrorBinaryTreeIteratively(tree.getRoot());
    tree.traversalInOrder();
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7
//        6
//      5
//    4
void Test2() {
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode *pNode8 = new BinaryTreeNode(8);
    BinaryTreeNode *pNode7 = new BinaryTreeNode(7);
    BinaryTreeNode *pNode6 = new BinaryTreeNode(6);
    BinaryTreeNode *pNode5 = new BinaryTreeNode(5);
    BinaryTreeNode *pNode4 = new BinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, nullptr);
    ConnectTreeNodes(pNode7, pNode6, nullptr);
    ConnectTreeNodes(pNode6, pNode5, nullptr);
    ConnectTreeNodes(pNode5, pNode4, nullptr);

    TraversalInOrder(pNode8);

    printf("=====Test2: MirrorBinaryTreeRecursively=====\n");
    MirrorBinaryTreeRecursively(pNode8);
    TraversalInOrder(pNode8);

    printf("=====Test2: MirrorBinaryTreeIteratively=====\n");
    MirrorBinaryTreeIteratively(pNode8);
    TraversalInOrder(pNode8);

    DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7
//              6
//               5
//                4
void Test3() {
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode *pNode8 = new BinaryTreeNode(8);
    BinaryTreeNode *pNode7 = new BinaryTreeNode(7);
    BinaryTreeNode *pNode6 = new BinaryTreeNode(6);
    BinaryTreeNode *pNode5 = new BinaryTreeNode(5);
    BinaryTreeNode *pNode4 = new BinaryTreeNode(4);

    ConnectTreeNodes(pNode8, nullptr, pNode7);
    ConnectTreeNodes(pNode7, nullptr, pNode6);
    ConnectTreeNodes(pNode6, nullptr, pNode5);
    ConnectTreeNodes(pNode5, nullptr, pNode4);

    TraversalInOrder(pNode8);

    printf("=====Test3: MirrorBinaryTreeRecursively=====\n");
    MirrorBinaryTreeRecursively(pNode8);
    TraversalInOrder(pNode8);

    printf("=====Test3: MirrorBinaryTreeIteratively=====\n");
    MirrorBinaryTreeRecursively(pNode8);
    TraversalInOrder(pNode8);

    DestroyTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void Test4() {
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode *pNode = nullptr;

    TraversalInOrder(pNode);

    printf("=====Test4: MirrorBinaryTreeRecursively=====\n");
    MirrorBinaryTreeRecursively(pNode);
    TraversalInOrder(pNode);

    printf("=====Test4: MirrorBinaryTreeIteratively=====\n");
    MirrorBinaryTreeRecursively(pNode);
    TraversalInOrder(pNode);
}

// 测试只有一个结点的二叉树
void Test5() {
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode *pNode8 = new BinaryTreeNode(8);

    TraversalInOrder(pNode8);

    printf("=====Test5: MirrorBinaryTreeRecursively=====\n");
    MirrorBinaryTreeRecursively(pNode8);
    TraversalInOrder(pNode8);

    printf("=====Test5: MirrorBinaryTreeIteratively=====\n");
    MirrorBinaryTreeRecursively(pNode8);
    TraversalInOrder(pNode8);
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
    test27::run();
    return 0;
}

