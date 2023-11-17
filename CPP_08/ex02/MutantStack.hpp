#ifndef MUTANT_H
#define MUTANT_H
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
    virtual ~MutantStack() {}
    MutantStack<T> &operator=(const MutantStack<T> &other)
    {
        std::stack<T>::operator=(other);
        return *this;
    }

    iterator begin()
    {
        return std::stack<T>::c.begin();
    }
    const_iterator begin() const
    {
        return std::stack<T>::c.begin();
    }
    iterator end()
    {
        return std::stack<T>::c.end();
    }
    const_iterator end() const
    {
        return std::stack<T>::c.end();
    }
    reverse_iterator rbegin()
    {
        return std::stack<T>::c.rbegin();
    }
    const_reverse_iterator rbegin() const
    {
        return std::stack<T>::c.rbegin();
    }
    reverse_iterator rend()
    {
        return std::stack<T>::c.rend();
    }
    const_reverse_iterator rend() const
    {
        return std::stack<T>::c.rend();
    }
};

#endif