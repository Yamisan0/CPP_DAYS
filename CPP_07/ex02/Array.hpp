#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <iostream>

template <typename T>

class Array{
    private:
        T* tab;
        unsigned int length;
    public:
        Array():tab(NULL), length(0){}
        Array(unsigned int n):tab(new T[n]), length(n){}
        ~Array(){
            delete[] tab;
        }
        Array(const Array& to_copy):tab(new T[to_copy.length]), length(to_copy.length){
            for (unsigned int i = 0; i < length; i++)
                tab[i] = to_copy.tab[i];
        }
        Array& operator = (const Array& rhs){
            if (this != &rhs){
                delete[] this->tab;
                tab = new T[rhs.length];
                length = rhs.length;
                for (unsigned int i = 0; i < length; i++)
                    tab[i] = rhs.tab[i];
            }
            return (*this);
        }

        T& operator [] (unsigned int index){
            if (index >= length)
                throw std::out_of_range("Out of range!");
            return tab[index];
        }

        const T& operator[](unsigned int index) const // read only
		{
    		if (index >= this->length)
	        	throw std::out_of_range("Index out of range");
    		return this->tab[index];
		}

    	unsigned int size() const 
		{
    	    return this->length;
    	}
};




#endif