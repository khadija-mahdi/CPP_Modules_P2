#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <ctime>

template<typename fun>
void print(const fun& arrayElement){
    std::cout << "Array Element is : " << arrayElement << std::endl;
}

template <typename Array ,typename FUN>
void iter(Array array[], size_t length, FUN fun){
    for (size_t i = 0; i < length; i++)
        fun(array[i]);
}


#endif