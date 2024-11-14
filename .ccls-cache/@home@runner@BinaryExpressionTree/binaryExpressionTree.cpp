#include "binaryExpressionTree.h"
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <cstdlib> // for stod()

template <class elemType>
binaryExpressionTree<elemType>::binaryExpressionTree() : binaryTreeType<elemType>() {}

template <class elemType>
double binaryExpressionTree<elemType>::evaluate(typename binaryTreeType<elemType>::nodeType* node) {
    if (!node) return 0;

    // If it's a leaf node (operand), return its value
    if (!node->lLink && !node->rLink) {
        return std::stod(node->info); // Convert string to double
    }

    // Otherwise, it's an operator node
    double leftVal = evaluate(node->lLink);
    double rightVal = evaluate(node->rLink);
    char op = node->info[0];

    switch (op) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        default: return 0; // Error, unsupported operator
    }
}

template <class elemType>
void binaryExpressionTree<elemType>::evaluateExpressionTree() {
    if (this->root) {
        double result = evaluate(this->root);
        std::cout << "Expression result: " << result << std::endl;
    } else {
        std::cout << "Expression tree is empty." << std::endl;
    }
}

template <class elemType>
void binaryExpressionTree<elemType>::buildExpressionTree(const std::string& postfixExpression) {
    std::stack<typename binaryTreeType<elemType>::nodeType*> treeStack;
    std::istringstream stream(postfixExpression);
    std::string token;

    while (stream >> token) {
        if (isdigit(token[0])) { // Operand (number)
            typename binaryTreeType<elemType>::nodeType* newNode = new typename binaryTreeType<elemType>::nodeType{token, nullptr, nullptr};
            treeStack.push(newNode);
        } else if (token == "+" || token == "-" || token == "*" || token == "/") { // Operator
            typename binaryTreeType<elemType>::nodeType* newNode = new typename binaryTreeType<elemType>::nodeType{token, nullptr, nullptr};
            if (!treeStack.empty()) {
                newNode->rLink = treeStack.top();
                treeStack.pop();
            }
            if (!treeStack.empty()) {
                newNode->lLink = treeStack.top();
                treeStack.pop();
            }
            treeStack.push(newNode);
        } else {
            std::cerr << "Unsupported token: " << token << std::endl;
            return;
        }
    }

    // The last node on the stack is the root of the tree
    if (!treeStack.empty()) {
        this->root = treeStack.top();
        treeStack.pop();
    }
}

template <class elemType>
void binaryExpressionTree<elemType>::destroyTree(typename binaryTreeType<elemType>::nodeType* node) {
    if (node) {
        destroyTree(node->lLink);
        destroyTree(node->rLink);
        delete node;
    }
}

template class binaryExpressionTree<std::string>; // Explicit template instantiation for std::string
