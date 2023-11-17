#include "Base.hpp"
#include <ctime>
#include <stdexcept>

Base* generate() 
{
    int n = rand() % 3;

    if (n == 0) 
    {
        std::cout << "generated an A class" << std::endl;
        return new A;
    } 
    else if (n == 1) 
    {
        std::cout << "generated a B class" << std::endl;
        return new B;
    } 
    else if (n == 2) 
    {
        std::cout << "generated a C class" << std::endl;
        return new C;
    } 
    else 
    {
        std::cout << "can't generate a class" << std::endl; //never happenning btw
        return NULL;
    }
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p) != NULL) 
        std::cout << "p points to A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL) 
        std::cout << "p points to B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL) 
        std::cout << "p points to C" << std::endl;
    else
        std::cout << "Can't identify the class" << std::endl;
}

void identify(Base& p) 
{
    try 
    {
        A& tmp = dynamic_cast<A&>(p);
        (void)tmp;
        std::cout << "p points to A" << std::endl;
        return;
    } 
    catch (...) {}

    try 
    {
        B& tmp = dynamic_cast<B&>(p);
        (void)tmp;
        std::cout << "p points to B" << std::endl;
        return;
    } 
    catch (...) {}

    try 
    {
        C& tmp = dynamic_cast<C&>(p);
        (void)tmp;
        std::cout << "p points to C" << std::endl;
        return;
    } 
    catch (...) {}

    std::cout << "Can't identify the class" << std::endl;
}

int main() 
{
    std::srand(static_cast<unsigned int>(time(NULL)));

    Base* base = generate();
    identify(base); // ptr
    identify(*base); // ref

    delete base;

    return 0;
}