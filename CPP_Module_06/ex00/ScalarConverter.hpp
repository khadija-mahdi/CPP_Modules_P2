#ifndef  ScalarConverter_CPP
#define  ScalarConverter_CPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

class  ScalarConverter{
private:
	 ScalarConverter(); // ---> default constructor
public:

/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical Form :    							   */
/*-----------------------------------------------------------------------------*/

	 ScalarConverter(const  ScalarConverter & ScalarConverterPoint); // ---> copy constructor 
	 ScalarConverter &operator=(const  ScalarConverter & ScalarConverterPoint); //--> Copy assignment operator 
	~ ScalarConverter();// destructor

/*-------------------------------------------------------------------------------*/

static void convert(const std::string& input);

/*----------------------------------------*/

};

void isChar(const std::string &s);
bool doubleCharacter(const std::string& str);
void isFloat(const std::string &str);
void isInteger(const std::string &str);
void isDouble(const std::string &str);
#endif