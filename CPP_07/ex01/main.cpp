#include <iostream>
#include "iter.hpp"

void printInt(int const &number) 
{
    std::cout << "Integer: " << number << std::endl;
}

void printString(std::string const &text) 
{
    std::cout << "String: " << text << std::endl;
}

template <typename T>
void displaySquare(T const &value) 
{
    std::cout << "Square: " << value * value << std::endl;
}

template < typename T >
void printPlusOne(T const &nb)
{
    std::cout << "Integer + one: " << nb + 1 << std::endl;
}

int main() 
{
    int integers[] = {1, 2, 3, 4, 5};
    std::cout << "Displaying Integers:" << std::endl;
    ::iter(integers, 5, ::printInt);
    std::cout << std::endl;

    std::string strings[] = {"apple", "banana", "cherry", "date"};
    std::cout << "Displaying Strings:" << std::endl;
    ::iter(strings, 4, ::printString);
    std::cout << std::endl;

    std::cout << "Displaying Squares of Integers:" << std::endl;
    ::iter(integers, 5, ::displaySquare);
    std::cout << std::endl;

    std::cout << "Displaying Integers + 1:" << std::endl;
    ::iter(integers, 5, ::printPlusOne);

    return 0;
}