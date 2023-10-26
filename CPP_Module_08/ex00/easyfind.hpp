#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>

using std::cout;
using std::endl;
template <typename T>
void easyfind(T &container, int find) {
    typename T::iterator itr = std::find(container.begin(), container.end(), find);
    if (itr != container.end()) {
        std::cout << "the occurrence is find : " << find << std::endl;
    }
    else
        throw std::runtime_error("not found");
}

#endif