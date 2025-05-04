#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int applyOperator(const std::string& op, int a, int b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("Error: division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: unknown operator");
}

int evaluateRPN(const std::string& expr) {
    std::istringstream iss(expr);
    std::stack<int> stk;
    std::string token;

    while (iss >> token) {
        if (isOperator(token)) {
            if (stk.size() < 2) throw std::runtime_error("Error: insufficient operands");
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(applyOperator(token, a, b));
        } else if (token.length() == 1 && isdigit(token[0])) {
            stk.push(token[0] - '0');
        } else {
            throw std::runtime_error("Error: invalid token " + token);
        }
    }

    if (stk.size() != 1) throw std::runtime_error("Error: malformed expression");
    return stk.top();
}
