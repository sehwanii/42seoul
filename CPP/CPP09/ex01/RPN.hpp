#ifndef RPN_HPP
#define RPN_HPP

#include <string>

bool isOperator(const std::string& token);
int applyOperator(const std::string& op, int a, int b);
int evaluateRPN(const std::string& expr);

#endif
