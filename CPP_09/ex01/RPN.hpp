#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <algorithm>

class RPN
{
private:
    std::stack<int> _numbers;
    int _error;

public:
    RPN(void);
    RPN(const RPN &other);
    ~RPN(void);
    RPN &operator=(const RPN &rhs);

    int calculate(char *str);
    int operation(int a, int b, char signe);
    int getError(void);
};

#endif