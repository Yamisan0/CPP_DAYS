#include "Span.hpp"
#include <iostream>

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

void small() 
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl << std::endl;
}

void big() 
{
    const unsigned int size = 10000;
    Span sp = Span(size);
    
    std::srand(std::time(0));
    for (unsigned int i = 0; i < size; i++) 
    {
        sp.addNumber(std::rand() % 10000);
    }
    std::cout << "Shortest span for 1,000 numbers: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span for 1,000 numbers: " << sp.longestSpan() << std::endl;
    std::cout << std::endl << std::endl;
}

void exception() 
{
    try 
    {
        Span sp = Span(2);
        sp.addNumber(5);
        std::cout << "Shortest span for 1 number: " << sp.shortestSpan() << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try 
    {
        Span sp = Span(1);
        sp.addNumber(5);
        sp.addNumber(10);
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

int main() 
{
    small();
    big();
    exception();
    return 0;
}