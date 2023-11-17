#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int nb):_nb(nb){}

Span::Span(Span& to_copy){
    *this = to_copy;
}

Span::~Span(){}

Span& Span::operator=(Span& rhs){
    if (this != &rhs){
        _vec = rhs._vec;
        _nb = rhs._nb;
    }
    return (*this);
}

void Span::addNumber(int nb){
    if (this->_vec.size() < this->_nb)
        _vec.push_back(nb);
    else
        throw( alreadyFull());
}

void Span::printSpan(void){
    std::vector<int>::iterator iter;

    for (iter = _vec.begin(); iter < _vec.end(); ++iter)
        std::cout << *iter << std::endl;
}

unsigned int    Span::longestSpan( void ){
    if ( _vec.size() < 2 )
        throw std::out_of_range("Span::longestSpan: list is empty");
    return ( *std::max_element( _vec.begin(), _vec.end() ) - *std::min_element( _vec.begin(), _vec.end() ) );
}

unsigned int Span::shortestSpan(void){
    if ( _vec.size() < 2 )
        throw std::out_of_range("Span::shortestSpan: list is empty");
    
    std::vector<int> copy;
    copy = _vec;

    std::sort(copy.begin(), copy.end());
    std::vector<int>::iterator iter;
    std::vector<int>::iterator iter2 = copy.begin();
    unsigned int min = longestSpan();

    for (iter = copy.begin() + 1; iter < copy.end(); ++iter){
        if (std::abs(*iter) == std::abs(*iter2))
            continue;
        if (std::abs(*iter2 - *iter) < static_cast<int>(min))
            min = std::abs(*iter2 - *iter);
        ++iter2;
    }
    return (min);
}

