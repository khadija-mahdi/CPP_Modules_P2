#include "Span.hpp"

/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

Span::Span(){
	this->span = new 
}

Span::Span(const Span &Span){
	*this = Span;
}

Span& Span::operator=(const Span &Span){
	if (this != &Span)
	{
		this->N = Span.N;
		this->span = Span.span;
	}
	return *this;
}

Span::~Span(){

}
/*-------------------------------------------------------------------------------------------*/

Span::Span(const unsigned int &N):N(N),span(N){
}

void Span::addNumber(int Number){
	static int pos = 0;
	if (pos < N)
	{
		span.push_front(Number);
		pos++;
	}
	else
		throw std::runtime_error("out of range");
}

// unsigned int Span::shortestSpan(){
// 	std::sort(span.begin(), span.end());
// 	// return (span.cend() - span.cbegin());
// }

// unsigned int Span::longestSpan(){
// 	std::sort(span.begin(), span.end());
// 	// return (span.cend() - span.cbegin());
// } 