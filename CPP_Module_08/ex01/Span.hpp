#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <iterator>

class Span{
	unsigned int N;
	int *span;
public:

/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical Form :    							   */
/*-----------------------------------------------------------------------------*/

	Span(); // ---> default constructor
	Span(const Span &Span); // ---> copy constructor 
	Span &operator=(const Span &Span); //--> Copy assignment operator 
	~Span();// destructor

/*-------------------------------------------------------------------------------*/
	Span(const unsigned int &N);
	void addNumber(int N);
	// unsigned int shortestSpan();
	// unsigned int longestSpan();
	void printSpan(){
		for(size_t ptr = 0 ; ptr <  N; ++ptr){
			std::cout << *ptr << std::endl;
		}
    }
};

#endif