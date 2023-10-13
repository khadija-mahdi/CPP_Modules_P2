#ifndef A_CPP
#define A_CPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include "Base.hpp"

class A :public Base{
public:
};

void identify(Base& p);
Base * generate(void);
void identify(Base* p);
#endif