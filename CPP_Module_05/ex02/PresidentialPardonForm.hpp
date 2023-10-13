#ifndef PRESIDENTIALPARDONFORM_CPP
#define PRESIDENTIALPARDONFORM_CPP

#include "AForm.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <fstream>


class AForm;
class PresidentialPardonForm : public AForm{
private:
	std::string target;
public:

/*-----------------------------------------------------------------------------------------------------------------------*/
/*				                         Orthodox Canonical Form :    						       			  	         */
/*-----------------------------------------------------------------------------------------------------------------------*/

	PresidentialPardonForm(); // ---> default constructor
	PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonFormPoint); // ---> copy constructor 
	PresidentialPardonForm &operator=(const PresidentialPardonForm &PresidentialPardonFormPoint); //--> Copy assignment operator 
	virtual ~PresidentialPardonForm();// destructor

/*--------------------------------------------------------------------------------------------------------------------------*/
/*			                            PresidentialPardonForm member functions :					                        */
/*--------------------------------------------------------------------------------------------------------------------------*/

    PresidentialPardonForm(const std::string& target);
	virtual void execute(Bureaucrat const & executor) const;
};
#endif