//
// Created by Silin Li on 16:03 01/31/2020.
// 

#ifndef CODINGINTERVIEW_BINARYTREE_H
#define CODINGINTERVIEW_BINARYTREE_H
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>

namespace Algorithm{

template<typename T>
struct BinaryTreeNode {
    explicit BinaryTreeNode(const T &d = 0) : data(d), left(nullptr), right(nullptr), parent(nullptr) {}
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *parent;//for get next node

    bool hasChild() const { return left || right; }
    void setParent(BinaryTreeNode<T> *node) {
        if (parent != node)
            parent = node;
    }
};


template<typename T>
void TraversalPreOrderCore(BinaryTreeNode<T> *node) {
    if (!node)
        return;
    std::cout << node->data << " ";
    TraversalPreOrderCore(node->left);
    TraversalPreOrderCore(node->right);
}
/**
 * @brief parent-->left-->right
 */
template<typename T>
void TraversalPreOrder(BinaryTreeNode<T> *node) {
    std::cout << "traversal pre order" << std::endl;
    TraversalPreOrderCore(node);
    std::cout << std::endl;
}

/**
 * @brief left-->parent-->right
 */
template<typename T>
void TraversalInOrderCore(BinaryTreeNode<T> *node) {
    if (!node)
        return;
    TraversalInOrderCore(node->left);
    std::cout << node->data << " ";
    TraversalInOrderCore(node->right);
}

template<typename T>
void TraversalInOrder(BinaryTreeNode<T> *node) {
    std::cout << "traversal in order\n";
    TraversalInOrderCore(node);
    std::cout << std::endl;
}


/**
 * @brief left-->right-->parent
 */
template<typename T>
void TraversalPostOrderCore(BinaryTreeNode<T> *node) {
    if (!node)
        return;
    TraversalPostOrderCore(node->left);
    TraversalPostOrderCore(node->right);
    std::cout << node->data << " ";
}

template<typename T>
void TraversalPostOrder(BinaryTreeNode<T> *node) {
    std::cout << "traversal post order\n";
    TraversalPostOrderCore(node);
    std::cout << std::endl;
}
/**
 * @brief free memory of a tree
 * left-->right-->parent
 * 传递引用是必要的，否则root本身内存释放会不对
 */
template<typename T>
void ReleaseTree(BinaryTreeNode<T> *&node) {
    if (!node)
        return;

    ReleaseTree(node->left);
    ReleaseTree(node->right);

    // delete a node
    std::cout << "delete node " << node->data << std::endl;
    delete node;//释放内存使其变成了野指针
    node = nullptr;//这一步是必要的
}

template<typename T>
struct BinaryTreeVisitNode {
    explicit BinaryTreeVisitNode(BinaryTreeNode<T> *&nd, bool vis = false) : node(nd), visited(vis) {}
    BinaryTreeNode<T> *node;
    bool visited;// only for post traversal iteratively
};

/**
 * @brief less is in left
 */
template<typename T>
class BinaryTree {
public:
    using NodeType = BinaryTreeNode<T>;
    using VisitNodeType = BinaryTreeVisitNode<T>;
public:
    BinaryTree() : root_(nullptr), sz_(0) {}
    explicit BinaryTree(const T &d) : root_(new NodeType(d)), sz_(0) {}
    ~BinaryTree() { releaseTree(root_); }

    void setRoot(NodeType *root) {
        releaseTree(root_);
        root_ = root;
    }
    NodeType *&getRoot() { return root_; }
    bool isEmpty() const { return !root_; }


    /**
     * @brief insert a node with data
     * @param d
     * @return
     */
    void insertSorted(const T &d) {
        insertCore(root_, d);
        ++sz_;
    }

    /**
     * @brief please make sure node is empty
     * if the node is already exist, then change its data
     * 此处必须是引用或者双重指针
     * 如果不是，那么传入的将是一个指针的拷贝，也就是拷贝指针指向了一个
     * 分配的内存，和原本指针半毛钱关系都没有
     * 如果是修改指针指向的数据的话，那么就无关紧要的；如果是修改指针本身，必须引用！！
     */
    void insertFreely(NodeType *&node, const T &d) {
        if (node) {
            node->data = d;
        }
        else {
            node = new NodeType(d);
        }
        ++sz_;
    }

    //-------------------------------------------------------------
    // traversal binary tree recursively
    //-------------------------------------------------------------
    void traversalPreOrder() {
        std::cout << "traversal pre order\n";
        traversalPreOrderCore(root_);
        std::cout << std::endl;
    }
    void traversalInOrder() {
        std::cout << "traversal in order\n";
        traversalInOrderCore(root_);
        std::cout << std::endl;
    }
    void traversalPostOrder() {
        std::cout << "traversal post order\n";
        traversalPostOrderCore(root_);
        std::cout << std::endl;
    }

    //------------------------------------------------------------
    // traversal binary tree iteratively
    // https://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html
    //------------------------------------------------------------
    /**
     * @brief use queue to implement traversal with pre-order
     * 辅助stack
     */
    void traversalPreOrderIteratively() {
        if (isEmpty()) {
            return;
        }

        std::cout << "traversal pre order iterativelly\n";

        std::stack<NodeType *> nodes;
        nodes.push(root_);
        while (!nodes.empty()) {
            NodeType *cur_node = nodes.top();

            // traversal with pre order
            std::cout << cur_node->data << " ";
            nodes.pop();

            // push right
            if (cur_node->right) {
                nodes.push(cur_node->right);
            }

            // push left
            if (cur_node->left) {
                nodes.push(cur_node->left);
            }
        }
        std::cout << std::endl;
    }

    /**
     * @brief 辅助stack
     */
    void traversalPreOrderIteratively2() {
        if (isEmpty())
            return;
        std::cout << "traversal pre order iterativelly2\n";

        std::stack<NodeType *> nodes;
        NodeType *cur_node = getRoot();
        while (!nodes.empty() || cur_node) {
            while (cur_node) {
                std::cout << cur_node->data << " ";// traversal with pre order
                nodes.push(cur_node);
                cur_node = cur_node->left;
            }

            if (!nodes.empty()) {
                cur_node = nodes.top();
                nodes.pop();
                cur_node = cur_node->right;
            }
        }
        std::cout << std::endl;
    }

    /**
     * @brief 辅助stack
     */
    void traversalInOrderIteratively() {
        if (isEmpty())
            return;
        std::cout << "traversal in order iterativelly\n";

        std::stack<NodeType *> nodes;
        NodeType *cur_node = getRoot();
        while (!nodes.empty() || cur_node) {
            while (cur_node) {
                nodes.push(cur_node);
                cur_node = cur_node->left;
            }

            if (!nodes.empty()) {
                cur_node = nodes.top();
                std::cout << cur_node->data << " ";// traversal with in order
                nodes.pop();
                cur_node = cur_node->right;
            }
        }
        std::cout << std::endl;
    }

    /**
     * @brief 辅助标志变量
     */
    void traversalPostOrderIteratively2() {
        if (isEmpty())
            return;
        std::cout << "traversal post order iterativelly\n";

        std::stack<VisitNodeType *> nodes;
        NodeType *cur_node = getRoot();
        VisitNodeType *visit_node = nullptr;
        while (!nodes.empty() || cur_node) {
            while (cur_node) {
                visit_node = new VisitNodeType(cur_node, true);
                nodes.push(visit_node);
                cur_node = cur_node->left;
            }

            if (!nodes.empty()) {
                visit_node = nodes.top();
                if (visit_node->visited) {
                    visit_node->visited = false;
                    cur_node = visit_node->node->right;
                }
                else {//not visited
                    std::cout << visit_node->node->data << " ";// traversal with in order
                    nodes.pop();
                    cur_node = nullptr;
                }
            }
        }
        std::cout << std::endl;
    }


    /**
     * @brief 层序遍历/宽度优先遍历 BFS
     * https://blog.csdn.net/ns_code/article/details/13169703
     */
    void traversalLevellOrder() {
        if (isEmpty())
            return;
        std::cout << "traversal level order " << std::endl;
        std::queue<NodeType *> nodes;
        nodes.push(getRoot());
        NodeType *cur_node = nullptr;
        while (!nodes.empty()) {
            cur_node = nodes.front();
            std::cout << cur_node->data << " ";
            nodes.pop();

            if (cur_node->left) {
                nodes.push(cur_node->left);
            }
            if (cur_node->right) {
                nodes.push(cur_node->right);
            }
        }
        std::cout << std::endl;
    }

    /**
     * @brief 深度优先遍历 DFS
     * 实质上就是前序遍历
     */
    void traversalDepthOrder() {
        traversalPreOrderIteratively();
    }


private:
    void insertCore(NodeType *&root, const T &d) {
        if (!root) {
            root = new NodeType(d);
            return;
        }
        if (root->data <= d) {
            insertCore(root->right, d);
        }
        else {
            insertCore(root->left, d);
        }
    }


    void traversalPreOrderCore(NodeType *node) {
        if (!node) {
            return;
        }
        std::cout << node->data << " ";
        traversalPreOrderCore(node->left);
        traversalPreOrderCore(node->right);
    }

    void traversalInOrderCore(NodeType *node) {
        if (!node) {
            return;
        }
        traversalInOrderCore(node->left);
        std::cout << node->data << " ";
        traversalInOrderCore(node->right);
    }

    void traversalPostOrderCore(NodeType *node) {
        if (!node) {
            return;
        }
        traversalPostOrderCore(node->left);
        traversalPostOrderCore(node->right);
        std::cout << node->data << " ";
    }
    /**
     * @brief free memory of a tree
     * release 采用后序遍历
     * left-->right-->parent
     * 传递引用是必要的，否则root本身内存释放会不对
     */
    void releaseTree(NodeType *&node) {
        if (!node)
            return;

        releaseTree(node->left);
        releaseTree(node->right);

        // delete a node
//        std::cout << "delete node " << node->data << std::endl;
        delete node;//释放内存使其变成了野指针
        node = nullptr;//这一步是必要的
    }

    NodeType *root_;
    size_t sz_;
};


}
#endif //CODINGINTERVIEW_BINARYTREE_H
