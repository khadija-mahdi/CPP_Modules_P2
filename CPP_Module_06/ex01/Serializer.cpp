#include "Serializer.hpp"

/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

Serializer::Serializer(){
		std::cout <<"Serializer "<< "default constructor called :)" << std::endl;
}

Serializer::Serializer(const Serializer &Serializer){
	std::cout << "Serializer copy constructor called :)" << std::endl;
	*this = Serializer;
}

Serializer& Serializer::operator=(const Serializer &Serializer){
	if (this != &Serializer)
	{
		std::cout << "Serializer assignment operator called :)" << std::endl;
		this->operator=(Serializer);
	}
	return *this;
}

Serializer::~Serializer(){
	std::cout <<"destructor destroyed Serializer" << std::endl;
}
/*-------------------------------------------------------------------------------------------*/

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t nptr = reinterpret_cast<uintptr_t>(ptr);
	return nptr;
}

Data *Serializer::deserialize(uintptr_t raw){
	Data *nptr = reinterpret_cast<Data*>(raw);
	return nptr;
}
