// binaryTree.h
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>
using namespace std;

// Definition of the Node
template <class elemType>
struct nodeType {
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};

// Definition of the class
template <class elemType>
class binaryTreeType {
protected:
    nodeType<elemType> *root;

public:
    bool isEmpty() const;
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    void destroyTree();
    binaryTreeType();
    ~binaryTreeType();

protected:
    void inorder(nodeType<elemType> *p) const;
    void preorder(nodeType<elemType> *p) const;
    void postorder(nodeType<elemType> *p) const;
    int height(nodeType<elemType> *p) const;
    int nodeCount(nodeType<elemType> *p) const;
    int leavesCount(nodeType<elemType> *p) const;
};

template <class elemType>
binaryTreeType<elemType>::binaryTreeType() {
    root = nullptr;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const {
    return (root == nullptr);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const {
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const {
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const {
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const {
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const {
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const {
    return leavesCount(root);
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree() {
    destroy(root);
}

// Helper functions for traversals and calculations
template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) const {
    if (p != nullptr) {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p) const {
    if (p != nullptr) {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p) const {
    if (p != nullptr) {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

template <class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p) const {
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p) const {
    if (p == nullptr)
        return 0;
    else
        return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) const {
    if (p == nullptr)
        return 0;
    else if (p->lLink == nullptr && p->rLink == nullptr)
        return 1; // p is a leaf node
    else
        return leavesCount(p->lLink) + leavesCount(p->rLink);
}

#endif
