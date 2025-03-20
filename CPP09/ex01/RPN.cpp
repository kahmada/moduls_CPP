#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    this->_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperation(const std::string &op, int a, int b) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            std::cerr << "Error: Division by zero" << std::endl;
            exit(1);
        }
        return a / b;
    }
    return 0;
}

int RPN::evaluate(const std::string &expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (isdigit(token[0]) && token.size() == 1) {
            _stack.push(atoi(token.c_str()));
        } else if (isOperator(token)) {
            if (_stack.size() < 2) {
                std::cerr << "Error: Invalid expression" << std::endl;
                exit(1);
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            _stack.push(applyOperation(token, a, b));
        } else {
            std::cerr << "Error: Invalid token -> " << token << std::endl;
            exit(1);
        }
    }
    
    if (_stack.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        exit(1);
    }
    return _stack.top();
}
