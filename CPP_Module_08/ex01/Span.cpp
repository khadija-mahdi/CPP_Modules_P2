#include "Span.hpp"

/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

Span::Span(){
	this->span = new int[0];
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
		delete[] span;
}
/*-------------------------------------------------------------------------------------------*/

Span::Span(const unsigned int &N):N(N){
	this->span = new int[N];
}

void Span::addNumber(int Number){
	static unsigned int pos = 0;
	if (pos < N)
	{
		this->span[pos] = Number;
		pos++;
	}
	else
		throw std::runtime_error("out of range");
}

unsigned int Span::shortestSpan(){
	unsigned int def;
	unsigned int def2 = 4294967295;
	std::sort(span, span + N);
	for (unsigned int i = 0; i < N; ++i){
		if (i + 1 < N && abs(span[i + 1] - span[i]) < def)
			def = abs(span[i + 1] - span[i]);
		if (i + 1 < N && i + 2 < N && abs(span[i + 2] - span[i + 1]) < def)
			def2 = abs(span[i + 2] - span[i + 1]);
		if (def2 < def)
			def = def2;
	}
	return def;
}

unsigned int Span::longestSpan(){
	std::sort(span, span + N);
	return (span[N - 1] - span[0]);
} 