#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <map>
#include <vector>
#include <iterator>


template <typename T>

void easyfind(T &container, int find){
    typename T::iterator itr;
    for(itr = container.begin(); itr != container.end(); ++itr){
        if(find == *itr){
            std::cout << "the occurrence is find in iterator " << *itr << std::endl;
            return;
        }
    }
    throw std::runtime_error("not found");
}

#endif