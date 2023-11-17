#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <array>
#include <exception>


template <typename T>

typename T::iterator easyfind(T& container, typename T::value_type var){
    typename T::iterator iter;

    iter = std::find(container.begin(), container.end(), var);
    if (iter != container.end())
        return (iter);
    return (container.end());
}

#endif