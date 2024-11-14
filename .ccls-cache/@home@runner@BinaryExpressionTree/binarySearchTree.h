#ifndef H_binarySearchTree
#define H_binarySearchTree

#include "binaryTree.h"  // Include binaryTreeType

template <class elemType>
class binarySearchTree : public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const override;
    void insert(const elemType& insertItem) override;
    void deleteNode(const elemType& deleteItem) override;

    binarySearchTree();  // Default constructor
    binarySearchTree(const binarySearchTree<elemType>& otherTree);  // Copy constructor
    ~binarySearchTree();  // Destructor
};

// Function prototypes for the new methods in binarySearchTree
template <class elemType>
void binarySearchTree<elemType>::insert(const elemType& insertItem);

template <class elemType>
bool binarySearchTree<elemType>::search(const elemType& searchItem) const;

template <class elemType>
void binarySearchTree<elemType>::deleteNode(const elemType& deleteItem);

#endif
