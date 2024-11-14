
#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <string>
#include <stack>

using namespace std;

// Define the nodeType class
class nodeType {
public:
    string info;  // Holds the operator or operand
    nodeType* left;  // Pointer to left child
    nodeType* right;  // Pointer to right child

    nodeType(string value) : info(value), left(nullptr), right(nullptr) {}
};

// Expression tree class
class expressionTree {
private:
    nodeType* root;  // Root of the expression tree

    void deleteTree(nodeType* node);  // Helper function to delete the tree
    nodeType* constructTree(const string &expr);  // Build the tree from postfix expression
    int evaluatePostorder(nodeType* node);  // Evaluate the tree using postorder traversal
    bool isOperator(char ch);  // Check if character is an operator
    int applyOperator(int operand1, int operand2, char op);  // Apply the operator on operands

public:
    expressionTree();  // Constructor
    ~expressionTree();  // Destructor
    int evaluateExpression(const string &expr);  // Evaluate the postfix expression
};

#endif
