#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>


class RPN {
private:
    std::stack<int> _stack;
    bool isOp(const std::string &token) const;
    int applyOp(const std::string &op, int a, int b) const;

public:
    RPN();
    RPN(const RPN &);
    RPN &operator=(const RPN &);
    ~RPN();
    bool evaluate(const std::string &expression, int &result);
};

#endif
