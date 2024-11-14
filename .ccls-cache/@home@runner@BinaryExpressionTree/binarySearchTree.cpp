#include "binarySearchTree.h"
#include <iostream>

template <class elemType>
binarySearchTree<elemType>::binarySearchTree() {
    // Default constructor (inherits from binaryTreeType constructor)
}

template <class elemType>
binarySearchTree<elemType>::binarySearchTree(const binarySearchTree<elemType>& otherTree) : binaryTreeType<elemType>(otherTree) {
    // Copy constructor (inherits copy logic from binaryTreeType)
}

template <class elemType>
binarySearchTree<elemType>::~binarySearchTree() {
    // Destructor (inherits destroy logic from binaryTreeType)
}

template <class elemType>
void binarySearchTree<elemType>::insert(const elemType& insertItem) {
    nodeType<elemType> *current, *trailCurrent, *newNode;

    newNode = new nodeType<elemType>;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if (this->root == nullptr) {
        this->root = newNode;  // If tree is empty, new node becomes root
    } else {
        current = this->root;
        trailCurrent = nullptr;
        while (current != nullptr) {
            trailCurrent = current;
            if (insertItem < current->info) {
                current = current->lLink;  // Move to left subtree
            } else {
                current = current->rLink;  // Move to right subtree
            }
        }
        if (insertItem < trailCurrent->info) {
            trailCurrent->lLink = newNode;  // Insert as left child
        } else {
            trailCurrent->rLink = newNode;  // Insert as right child
        }
    }
}

template <class elemType>
bool binarySearchTree<elemType>::search(const elemType& searchItem) const {
    nodeType<elemType>* current = this->root;
    while (current != nullptr) {
        if (current->info == searchItem) {
            return true;  // Item found
        } else if (searchItem < current->info) {
            current = current->lLink;  // Move to left subtree
        } else {
            current = current->rLink;  // Move to right subtree
        }
    }
    return false;  // Item not found
}

template <class elemType>
void binarySearchTree<elemType>::deleteNode(const elemType& deleteItem) {
    nodeType<elemType> *current, *trailCurrent, *temp;

    if (this->root == nullptr) {
        std::cout << "Tree is empty. Cannot delete.\n";
        return;
    }

    current = this->root;
    trailCurrent = nullptr;
    while (current != nullptr && current->info != deleteItem) {
        trailCurrent = current;
        if (deleteItem < current->info) {
            current = current->lLink;  // Move to left subtree
        } else {
            current = current->rLink;  // Move to right subtree
        }
    }

    if (current == nullptr) {
        std::cout << "Item not found in the tree.\n";
        return;  // Item not found
    }

    // Case 1: Node to be deleted has no children (leaf node)
    if (current->lLink == nullptr && current->rLink == nullptr) {
        if (current == this->root) {
            this->root = nullptr;  // If root is to be deleted
        } else if (trailCurrent->lLink == current) {
            trailCurrent->lLink = nullptr;  // Left child of parent
        } else {
            trailCurrent->rLink = nullptr;  // Right child of parent
        }
        delete current;
    }
    // Case 2: Node to be deleted has one child
    else if (current->lLink == nullptr || current->rLink == nullptr) {
        temp = current;
        if (current->lLink != nullptr) {
            current = current->lLink;
        } else {
            current = current->rLink;
        }
        if (current == this->root) {
            this->root = current;  // If root is deleted
        } else if (trailCurrent->lLink == temp) {
            trailCurrent->lLink = current;
        } else {
            trailCurrent->rLink = current;
        }
        delete temp;
    }
    // Case 3: Node to be deleted has two children
    else {
        temp = current->rLink;
        while (temp->lLink != nullptr) {
            temp = temp->lLink;  // Find the minimum node in right subtree
        }
        current->info = temp->info;  // Replace current node's value with the successor's value
        deleteNode(temp->info);  // Delete the successor
    }
}
