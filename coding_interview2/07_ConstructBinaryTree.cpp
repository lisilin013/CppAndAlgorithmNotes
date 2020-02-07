//
// Created by Silin Li on 16:04 01/31/2020.
// 

#include "BinaryTree.h"

using namespace std;

namespace test7{

using Algorithm::BinaryTreeNode;
using Algorithm::BinaryTree;

/**
 * @brief new a binary tree to store integer data
 */
using NodeType = BinaryTreeNode<int>;
NodeType *GetBinaaryTree() {
    NodeType *root = new NodeType(1);
    root->left = new NodeType(2);
    root->left->left = new NodeType(4);
    root->left->left->right = new NodeType(7);

    root->right = new NodeType(3);
    root->right->left = new NodeType(5);
    root->right->right = new NodeType(6);
    root->right->right->left = new NodeType(8);
    return root;
}



/**
 * @brief easy version
 */
void run1() {
    auto tree = GetBinaaryTree();
    TraversalPreOrder(tree);
    cout << endl;
    TraversalInOrder(tree);
    cout << endl;
    TraversalPostOrder(tree);
    cout << endl;

    ReleaseTree(tree);
}

/**
 * @brief insert binary tree freely
 */
void run2() {
    BinaryTree<int> tree;
    tree.insertFreely(tree.getRoot(), 1);
    tree.insertFreely(tree.getRoot()->left, 2);
    tree.insertFreely(tree.getRoot()->left->left, 4);
    tree.insertFreely(tree.getRoot()->left->left->right, 7);

    tree.insertFreely(tree.getRoot()->right, 2);
    tree.insertFreely(tree.getRoot()->right->left, 5);
    tree.insertFreely(tree.getRoot()->right->right, 6);
    tree.insertFreely(tree.getRoot()->right->right->left, 8);

    tree.traversalPreOrder();
    tree.traversalPreOrderIteratively2();
    tree.traversalInOrder();
    tree.traversalPostOrder();
}

/**
 * @brief insert binary tree sorted
 */
void run3() {
    BinaryTree<int> tree;
    tree.insertSorted(10);
    tree.insertSorted(6);
    tree.insertSorted(14);
    tree.insertSorted(4);
    tree.insertSorted(8);
    tree.insertSorted(12);
    tree.insertSorted(16);
    tree.traversalPreOrder();
    tree.traversalPreOrderIteratively();
    tree.traversalPreOrderIteratively2();
    tree.traversalInOrder(); //中序遍历是有序的结果
    tree.traversalInOrderIteratively();
    tree.traversalPostOrder();
    tree.traversalPostOrderIteratively2();
    tree.traversalLevellOrder();
}

/**
 * @brief 根据pre_order和in_order重构二叉树
 * 关键是抓住
 * （1）前序遍历特点：parent-->left-->right，所以第一个值是root
 * （2）中序遍历特点：left-->parent-->right，root值的节点正好把左右子树分开
 * @param pre_start
 * @param pre_end
 * @param in_start
 * @param in_end
 * @return
 */
NodeType *ConstructBinaryTreeCore(int *pre_start, int *pre_end,
                                  int *in_start, int *in_end) {
    // 1. 前序遍历的第一个是root
    NodeType *root = new NodeType(pre_start[0]);

    if (pre_start == pre_end) {
        if (in_start == in_end)
            return root;
        else {
            cout << "ff\n";
            throw std::exception();
        }
    }

    // 2. 在中序遍历中找到root的位置
    int *in_root = in_start;
    while (*in_root != root->data && in_root <= in_end) {
        ++in_root;
    }
    if (in_root == in_end && *in_root != root->data) {
        cout << "ffs\n";
        throw std::exception();
    }

    // 3. 构建左右子树，闭区间分割 [a, b]
    int left_len = in_root - in_start;
    int *left_pre_end = pre_start + left_len;
    if (left_len > 0) {
        root->left = ConstructBinaryTreeCore(pre_start + 1, left_pre_end, in_start, in_root - 1);
    }
    int right_len = in_end - in_root;
    if (right_len > 0) {
        root->right = ConstructBinaryTreeCore(left_pre_end + 1, pre_end, in_root + 1, in_end);
    }

    return root;
}


NodeType *ConstructBinaryTree(int *pre_order, int *in_order, int len) {
    // check inputs
    if (!pre_order || !in_order || len <= 0) {
        cout << "inputs are illegal\n";
        return nullptr;
    }

    return ConstructBinaryTreeCore(pre_order, pre_order + len - 1, in_order, in_order + len - 1);
}


void ConstructBinaryTreeTest() {
    int pre[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int in[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    NodeType *root = ConstructBinaryTree(pre, in, 8);
    BinaryTree<int> tree;
    tree.setRoot(root);
    tree.traversalPreOrder();
    tree.traversalInOrder();
}
}

int main(int argc, char **argv) {
    test7::run1();
    return 0;
}

