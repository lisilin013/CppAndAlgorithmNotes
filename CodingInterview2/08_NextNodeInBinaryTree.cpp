//
// Created by Silin Li on 19:20 02/02/2020.
// 

#include "BinaryTree.h"

namespace test8{
using namespace Algorithm;
using namespace std;
using NodeType = BinaryTreeNode<char>;

/**
 * @brief find next node in in-order binary tree
 * @param node
 * @return
 */
NodeType *NextNodeInBinaryTreeWithInOrder(NodeType *node) {
    assert(node);
    // 有right，返回right 树最左边的node
    if (node->right) {
        NodeType *cur_node = node->right;
        while (cur_node->left) {
            cur_node = cur_node->left;
        }
        return cur_node;
    }
    else {//没有right，需要判断该node是位于left还是right
        //先判断是不是根节点
        if (!node->parent) {//是根节点并且没有right，本身就是最后一个节点，下一个为null
            return nullptr;
        }
            // 不是根节点，判断该node是位于left还是right
        else if (node == node->parent->left) {//位于left，且没有right
            return node->parent;
        }
        else if (node == node->parent->right) {//找到一个节点的parent为left的，返回node的parent
            NodeType *cur_node = node;
            while (cur_node->parent &&
                   cur_node == cur_node->parent->right) {
                cur_node = cur_node->parent;
            }
            return cur_node->parent;
        }
        else {
            return nullptr;
        }
    }
}

NodeType *NextNodeInBinaryTreeWithPostOrder(NodeType *node) {
    assert(node);

    // 根节点
    if (!node->parent) {
        return nullptr;
    }
    else if (node == node->parent->left) {//本身是left，就找父节点的right的最left的
        NodeType *cur_node = node->parent;
        NodeType *next_node = node->parent->right;
        while (next_node) {
            cur_node = next_node;
            next_node = next_node->left;
        }
        return cur_node;
    }
    else if (node == node->parent->right) {
        return node->parent;
    }
    else {
        cout << "Wrong Input Node!\n";
        return nullptr;
    }

}
void run() {
    // build a tree
    NodeType *a = new NodeType('a');
    NodeType *b = a->left = new NodeType('b');
    NodeType *c = a->right = new NodeType('c');
    b->setParent(a);
    c->setParent(a);

    NodeType *d = b->left = new NodeType('d');
    NodeType *e = b->right = new NodeType('e');
    d->setParent(b);
    e->setParent(b);

    NodeType *f = c->left = new NodeType('f');
    NodeType *g = c->right = new NodeType('g');
    f->setParent(c);
    g->setParent(c);

    NodeType *h = e->left = new NodeType('h');
    NodeType *i = e->right = new NodeType('i');
    h->setParent(e);
    i->setParent(e);

    // traversal a tree
    TraversalInOrder(a);
    cout << endl;


    // test next node
    std::vector<NodeType *> nodes;
    nodes.push_back(d);
    nodes.push_back(b);
    nodes.push_back(h);
    nodes.push_back(e);
    nodes.push_back(i);
    nodes.push_back(a);
    nodes.push_back(f);
    nodes.push_back(c);
    nodes.push_back(g);
    for (int j = 0; j < nodes.size(); ++j) {
        auto node = NextNodeInBinaryTreeWithInOrder(nodes[j]);
        if (node) {
            cout << nodes[j]->data << " next is " << node->data << endl;
        }
        else {
            cout << nodes[j]->data << " next is null" << endl;
        }
    }
    cout << "-----------------------------\n";
    TraversalPostOrder(a);
    cout << endl;
    nodes.clear();
    nodes.push_back(d);
    nodes.push_back(h);
    nodes.push_back(i);
    nodes.push_back(e);
    nodes.push_back(b);
    nodes.push_back(f);
    nodes.push_back(g);
    nodes.push_back(c);
    nodes.push_back(a);
    for (int k = 0; k < nodes.size(); ++k) {
        auto node = NextNodeInBinaryTreeWithPostOrder(nodes[k]);
        if (node) {
            cout << nodes[k]->data << " next is " << node->data << endl;
        }
        else {
            cout << nodes[k]->data << " is root, has no next node" << endl;
        }
    }
    // end
    cout << "-----------------------------\n";
    cout << "Begin to release the tree\n";
    ReleaseTree(a);
}
}


int main(int argc, char **argv) {
    test8::run();
    return 0;
}

