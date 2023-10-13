#ifndef  Serializer_CPP
#define  Serializer_CPP

#include <iostream>
#include <sstream>
#include <cstring>
#include <stdint.h>

struct Data
{
	int nbr;
	uintptr_t raw;
	std::string name;
	double a;
	Data(int n, uintptr_t r, const std::string &nm, double b):nbr(n),raw(r),name(nm),a(b){}
};

class  Serializer{
	 Serializer(); // ---> default constructor
public:

/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical Form :    							   */
/*-----------------------------------------------------------------------------*/

	 Serializer(const  Serializer & SerializerPoint); // ---> copy constructor 
	 Serializer &operator=(const  Serializer & SerializerPoint); //--> Copy assignment operator 
	~ Serializer();// destructor

/*-------------------------------------------------------------------------------*/

static uintptr_t serialize(Data* ptr);
static Data* deserialize(uintptr_t raw);

/*----------------------------------------*/

};

#endif