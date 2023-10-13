#ifndef  Intern_CPP
#define  Intern_CPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>

class AForm;
class  Intern{
private:
	const std::string name;
	int Rang;
public:

/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical Form :    							   */
/*-----------------------------------------------------------------------------*/

	 Intern(); // ---> default constructor
	 Intern(const  Intern & InternPoint); // ---> copy constructor 
	 Intern &operator=(const  Intern & InternPoint); //--> Copy assignment operator 
	~ Intern();// destructor

/*---------------------------------------------------------------------------------*/
/*			         Intern member functions :								   */
/*---------------------------------------------------------------------------------*/

	AForm *makeForm(const std::string &name,const std::string &target);

/*---------------------------------------------------------------------------------*/
/*	    		                AForm class :			              			   */
/*---------------------------------------------------------------------------------*/

	class WrongNameException :public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#include "AForm.hpp"
#endif