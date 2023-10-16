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

template<typename T>
void print(T const & arrayElement){
    std::cout << "Array Element is : " << arrayElement << std::endl;
}

template <typename T>
void iter(T array[], size_t length, void (*fun)(T const &)){
    for (size_t i = 0; i < length; i++)
        fun(array[i]);
}


#endif