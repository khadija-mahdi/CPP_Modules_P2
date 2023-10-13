#include "ScalarConverter.hpp"

/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

ScalarConverter::ScalarConverter(){
		std::cout <<"ScalarConverter "<< "default constructor called :)" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ScalarConverter){
	std::cout << "ScalarConverter copy constructor called :)" << std::endl;
	*this = ScalarConverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &ScalarConverter){
	if (this != &ScalarConverter)
	{
		std::cout << "ScalarConverter assignment operator called :)" << std::endl;
		this->operator=(ScalarConverter);
	}
	return *this;
}

ScalarConverter::~ScalarConverter(){
	std::cout <<"destructor destroyed ScalarConverter" << std::endl;
}
/*-------------------------------------------------------------------------------------------*/

void ScalarConverter::convert(const std::string& input){
    isChar(input);
    isInteger(input);
    isFloat(input);
    isDouble(input);
}
