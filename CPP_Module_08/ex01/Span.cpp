#include "Span.hpp"

/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

Span::Span(){
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

Span::Span(const unsigned int &N):N(N), span(N){
}

void Span::addNumber(int Number){
	static unsigned int pos = 0;
	if (pos < N)
	{
		this->span.pop_front();
		span.push_back(Number);
		pos++;
	}
	else
		throw std::runtime_error("out of range");
}

unsigned int Span::shortestSpan(){
	if (N <= 1)
		throw std::runtime_error("no span can be found");
	span.sort();
	std::list<int>::iterator ptr = this->span.begin();
	int at = *std::next(ptr) - *ptr;
	int def = at;
	while(ptr != std::prev(span.end())){
		if ((*std::next(ptr) - *ptr) < at)
			def = (*std::next(ptr) - *ptr);
		ptr++;
	}
	return def;
}

unsigned int Span::longestSpan(){
	if (N <= 1)
		throw std::runtime_error("no span can be found");
	this->span.sort();
	return (this->span.back() - this->span.front());
}


void Span::addNumbers(unsigned int pos){
	if (pos < N)
	{
		while(pos < N){
			this->span.pop_front();
			span.push_back(1337);
			pos++;
		}
	}
	else
		throw std::runtime_error("out of range");
}

void Span::printSpan(){
	std::list<int>::iterator ptr;
	for(ptr = this->span.begin() ; ptr != this->span.end(); ++ptr){
		std::cout << *ptr << std::endl;
		std::cout << "--------------------" <<std::endl;
	}
}

std::list<int> Span::getSpan(){
	return span;
}