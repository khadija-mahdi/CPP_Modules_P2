#ifndef ROBOTOMYREQUESTFORM_CPP
#define ROBOTOMYREQUESTFORM_CPP

#include "AForm.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <ctime>

class AForm;
class RobotomyRequestForm : public AForm{
private:
	std::string target;
public:

/*-----------------------------------------------------------------------------------------------------------------------*/
/*				                         Orthodox Canonical Form :    						       			  	         */
/*-----------------------------------------------------------------------------------------------------------------------*/

	RobotomyRequestForm(); // ---> default constructor
	RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestFormPoint); // ---> copy constructor 
	RobotomyRequestForm &operator=(const RobotomyRequestForm &RobotomyRequestFormPoint); //--> Copy assignment operator 
	virtual ~RobotomyRequestForm();// destructor

/*--------------------------------------------------------------------------------------------------------------------------*/
/*			                            RobotomyRequestForm member functions :					                        */
/*--------------------------------------------------------------------------------------------------------------------------*/

    RobotomyRequestForm(const std::string& target);
	virtual void execute(Bureaucrat const & executor) const;
};
#endif