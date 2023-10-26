#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
#include <deque>
#include <iterator>

template < typename T ,typename container = std::deque<T> >

class MutantStack : public std::stack<T>{
public:
    MutantStack():std::stack<T, container>(){}

    MutantStack(const  MutantStack &MutantStack):std::stack<T, container>(MutantStack){
        *this =  MutantStack;
    }

    MutantStack& operator=(const  MutantStack & MutantStack){
        if (this != & MutantStack)
            this->operator=(MutantStack);
        return *this;
    }
    ~MutantStack(){}
    
    typedef typename container::iterator iterator;
    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
       return this->c.end();
    }
};
#endif