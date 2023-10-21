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
		this->size = Span.size;
		this->span = std::vector<int>(Span.span.begin(), Span.span.end());
	}
	return *this;
}

Span::~Span(){
}
/*-------------------------------------------------------------------------------------------*/

Span::Span(const unsigned int &N):N(N), size(0){
}

void Span::addNumber(int Number){
	if (size < N)
	{
		span.push_back(Number);
		size++;
	}
	else
		throw std::runtime_error("out of range\n");
}

unsigned int Span::shortestSpan(){
	if (N <= 1 || size <= 1)
		throw std::runtime_error("no span can be found");
	sort(span.begin(), span.end());
	std::vector<int>::iterator ptr = this->span.begin();
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
	if (N <= 1 || size <= 1)
		throw std::runtime_error("no span can be found");
	sort(span.begin(), span.end());
	return (this->span.back() - this->span.front());
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	std::vector<int>::iterator it;
	this->size = 0;
	for(it = begin; it != end; it++)
		addNumber(*it);

}

void Span::printSpan(){
	std::vector<int>::iterator ptr;
		std::cout << "\n--------- list : -----------\n " <<std::endl;
	for(ptr = this->span.begin() ; ptr != this->span.end(); ++ptr){
		std::cout << *ptr << std::endl;
		std::cout << "--------------------" <<std::endl;
	}
}
