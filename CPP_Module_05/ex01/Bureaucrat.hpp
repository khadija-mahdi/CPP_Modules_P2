#ifndef BUREAUCRAT_CPP
#define BUREAUCRAT_CPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>

class Form;
class Bureaucrat{
private:
	const std::string name;
	int Grade;
public:

/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical Form :    							   */
/*-----------------------------------------------------------------------------*/

	Bureaucrat(); // ---> default constructor
	Bureaucrat(const Bureaucrat &BureaucratPoint); // ---> copy constructor 
	Bureaucrat &operator=(const Bureaucrat &BureaucratPoint); //--> Copy assignment operator 
	~Bureaucrat();// destructor

/*---------------------------------------------------------------------------------*/
/*			        Bureaucrat member functions :								   */
/*---------------------------------------------------------------------------------*/

    Bureaucrat(const std::string& s,const int &Grade);
	std::string getName()const;
	int getGrade()const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form);

/*---------------------------------------------------------------------------------*/
/*	    		             Bureaucrat class :			              			   */
/*---------------------------------------------------------------------------------*/

	class GradeTooLowException :public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
/*-------------------------------------------------------------------------------*/
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#include "Form.hpp"
#endif