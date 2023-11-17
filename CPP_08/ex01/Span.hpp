#ifndef SPAN_HPP
# define SPAN_HPP


#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>

class Span{
    private:
        std::vector<int> _vec;
        unsigned int     _nb;
        Span();
    public:
        Span(unsigned int nb);
        Span(Span& to_copy);
        ~Span(void);
        Span& operator = (Span& rhs);
        void addNumber(int nb);
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);
        
        void printSpan(void);
        
        
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            if(_vec.size() + std::distance(begin, end) > _nb)
                throw alreadyFull();
            while (begin != end)
            {
                addNumber(*begin);
                ++begin;
            }
        }

    class alreadyFull: public std::exception{
        public:
            virtual const char * what() const throw() {return "Span already full";}
    };

};

#endif