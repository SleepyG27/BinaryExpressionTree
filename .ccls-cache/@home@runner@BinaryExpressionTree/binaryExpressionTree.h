// expressionTree.h
#ifndef H_expressionTree
#define H_expressionTree

#include "binaryTree.h"
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class ExpressionTree : public binaryTreeType<char> {
public:
    void buildTreeFromRPN(const std::string& expression);
    int evaluate() const;

private:
    int evaluate(nodeType<char>* node) const;
    bool isOperator(char ch) const;
};

void ExpressionTree::buildTreeFromRPN(const std::string& expression) {
    std::stack<nodeType<char>*> stack;
    std::istringstream iss(expression);
    char token;

    while (iss >> token) {
        nodeType<char>* newNode = new nodeType<char>{token, nullptr, nullptr};
        if (isOperator(token)) {
            newNode->rLink = stack.top(); stack.pop();
            newNode->lLink = stack.top(); stack.pop();
        }
        stack.push(newNode);
    }
    root = stack.top();
}

int ExpressionTree::evaluate() const {
    return evaluate(root);
}

int ExpressionTree::evaluate(nodeType<char>* node) const {
    if (!isOperator(node->info))
        return node->info - '0';

    int left = evaluate(node->lLink);
    int right = evaluate(node->rLink);

    switch (node->info) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        default: throw std::invalid_argument("Invalid operator");
    }
}

bool ExpressionTree::isOperator(char ch) const {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

#endif
