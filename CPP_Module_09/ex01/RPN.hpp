#pragma "one"

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <time.h>

class RPN{
    std::stack<int> Data;
public:
/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical Form :    							   */
/*-----------------------------------------------------------------------------*/

	RPN(); // ---> default constructor
	RPN(const RPN &RPN); // ---> copy constructor 
	RPN &operator=(const RPN &RPN); //--> Copy assignment operator 
	~RPN();// destructor

/*-------------------------------------------------------------------------------*/
    void RPNExpression(char *expression);
};
