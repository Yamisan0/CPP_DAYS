#include "RPN.hpp"

RPN::RPN(void) : _error(0) {}

RPN::~RPN(void) {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        this->_numbers = rhs._numbers;
        _error = rhs._error;
    }
    return (*this);
}

int RPN::calculate(char *str)
{

    std::string arg(str);
    int         a;
    int         b;
    int val;

    for (size_t i = 0; i < arg.length(); i++)
    {
        if (arg[i] == ' ')
            continue;
        if (!std::isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+' && arg[i] != '/' && arg[i] != '*')
        {
            std::cerr << "Error: Unexpected character: " << arg[i] << std::endl;
            return (_error = 1, 0);
        }

        if (std::isdigit(arg[i])){
            if ((val = std::atoi(arg.c_str() + i)) > 9 || val < 0)
                return (_error = 1, std::cerr << "Error :number not in scope"  << std::endl, 0);

            else
            _numbers.push(std::atoi(arg.c_str() + i));

        }
        else if (arg[i] == '-' || arg[i] == '+' || arg[i] == '*' || arg[i] == '/')
        {
            if (_numbers.size() < 2)
                return (_error = 1, std::cout << "Error" << std::endl, 0);
            b = _numbers.top();
            _numbers.pop();
            a = _numbers.top();
            _numbers.pop();
            _numbers.push(operation(a, b, arg[i]));
        }
    }
    if (_numbers.size() > 1)
        return (_error = 1, std::cout << "Error" << std::endl, 0);
    return (_numbers.top());
}

int RPN::getError(void){
    return (_error);
}

int RPN::operation(int a, int b, char signe){
    switch (signe)
    {
    case '+':
        return a + b;
    case '-':
        return (a - b);
    case '/':
        return (a / b);
    case '*':
        return (a * b);
    }

    return (-1);
}