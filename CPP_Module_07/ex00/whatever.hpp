#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <ctime>

template <typename Swap>
void swap(Swap &a, Swap& b){
    Swap c = a;
    a = b;
    b = c;
}

template <typename Min>
Min &min(Min &a, Min& b)
{
    if (a < b)
        return a;
    return b;
}

template <typename Max>
Max &max(Max &a, Max& b)
{
    if (a > b)
        return a;
    return b;
}

#endif