#include <iostream>
#include "MutantStack.hpp"

int main()
{
    std::cout << "==== TEST 1 : push, top, pop, size ====" << std::endl;
    MutantStack<int> mstack;
    std::cout << "Pushing 5 and 17.... " << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element : " << mstack.top() << std::endl;
    std::cout << "Pushing 5 and 17.... " << std::endl;
    mstack.pop();
    std::cout << "Size after pop : " << mstack.size() << std::endl;

    std::cout << "\n==== TEST 2: Iteration ====" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "Elements using iterator: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << ";";
    }
    std::cout << std::endl;

    std::cout << "\n==== TEST 3: Const Iteration ====" << std::endl;
    const MutantStack<int> const_mstack = mstack;
    std::cout << "Elements using const_iterator: ";
    for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit)
    {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    std::cout << "\n==== TEST 4: Reverse Iteration ====" << std::endl;
    std::cout << "Elements using reverse_iterator: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    return 0;
}