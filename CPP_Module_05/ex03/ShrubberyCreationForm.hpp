#ifndef SHRUBBERYCREATIONFORM_CPP
#define SHRUBBERYCREATIONFORM_CPP

#include "AForm.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <fstream>


class AForm;
class ShrubberyCreationForm : public AForm{
private:
	std::string target;
public:

/*-----------------------------------------------------------------------------------------------------------------------*/
/*				                         Orthodox Canonical Form :    						       			  	         */
/*-----------------------------------------------------------------------------------------------------------------------*/

	ShrubberyCreationForm(); // ---> default constructor
	ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationFormPoint); // ---> copy constructor 
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ShrubberyCreationFormPoint); //--> Copy assignment operator 
	virtual ~ShrubberyCreationForm();// destructor

/*--------------------------------------------------------------------------------------------------------------------------*/
/*			                            ShrubberyCreationForm member functions :					                        */
/*--------------------------------------------------------------------------------------------------------------------------*/

    ShrubberyCreationForm(const std::string& target);
	virtual void execute(Bureaucrat const & executor) const;
};
#endif