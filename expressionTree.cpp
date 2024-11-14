
#include "expressionTree.h"
#include <sstream>
#include <stack>
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructor
expressionTree::expressionTree() {
    root = nullptr;  // Initialize root to null
}

// Destructor
expressionTree::~expressionTree() {
    deleteTree(root);
}

// Helper function to delete the tree
void expressionTree::deleteTree(nodeType* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Evaluate a postfix expression
int expressionTree::evaluateExpression(const string &expr) {
    stack<int> s;  // Stack to hold operands
    nodeType* root = constructTree(expr); // Build the tree from the expression

    // Perform an inorder traversal and evaluate the expression
    return evaluatePostorder(root);
}

// Helper function to evaluate a postorder traversal of the tree
int expressionTree::evaluatePostorder(nodeType* node) {
    if (node == nullptr) {
        return 0;
    }

    // If the node is an operator, evaluate its left and right subtrees
    if (isOperator(node->info[0])) {
        int leftVal = evaluatePostorder(node->left);
        int rightVal = evaluatePostorder(node->right);
        return applyOperator(leftVal, rightVal, node->info[0]);
    }

    // Otherwise, the node contains an operand, return its integer value
    return stoi(node->info);
}

// Construct an expression tree from a postfix expression
nodeType* expressionTree::constructTree(const string &expr) {
    stack<nodeType*> s;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        nodeType* newNode = new nodeType(token);

      
        if (isOperator(token[0])) {
            newNode->right = s.top(); s.pop();
            newNode->left = s.top(); s.pop();
        }

        s.push(newNode);
    }

    return s.top(); 
}

// Check if a character is an operator
bool expressionTree::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Apply the operator to two operands and return the result
int expressionTree::applyOperator(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) {
                throw runtime_error("Division by zero");
            }
            return operand1 / operand2;
        default: throw runtime_error("Unknown operator");
    }
}
