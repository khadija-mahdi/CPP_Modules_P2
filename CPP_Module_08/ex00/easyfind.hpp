#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>


template <typename T>

void easyfind(T &container, int find){
    typename T::iterator itr = std::find(container.begin(), container.end(), find);
    if (itr != container.end()){
        std::cout << "the occurrence is find in iterator " << *itr << std::endl;
    }
    else
        throw std::runtime_error("not found");
}

#endif