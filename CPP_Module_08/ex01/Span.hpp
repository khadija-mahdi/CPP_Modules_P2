#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>

class Span{
	unsigned int N;
	size_t size;
	std::vector<int> span;
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
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void printSpan();
};

#endif