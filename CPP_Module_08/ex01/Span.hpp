#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include <iterator>

class Span{
	unsigned int N;
	std::list<int> span;
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
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void addNumbers(unsigned int pos);
	void printSpan();
	std::list<int> getSpan();
};

#endif