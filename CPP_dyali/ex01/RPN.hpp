#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>

class RPN {
private:
    std::stack<int> _stack;
    bool isOperator(const std::string &token) const;
    int applyOperation(const std::string &op, int a, int b) const;

public:
    RPN();
    RPN(const RPN &);
    RPN &operator=(const RPN &);
    ~RPN();

    int evaluate(const std::string &expression);
};

#endif
