#ifndef FORM_CPP
#define FORM_CPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>

class Bureaucrat;
class Form{
private:
	std::string name;
	bool iSsigned;
	const int GradeSigned;
	const int GradeExecuted;
public:

/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical Form :    							   */
/*-----------------------------------------------------------------------------*/

	Form(); // ---> default constructor
	Form(const Form &FormPoint); // ---> copy constructor 
	Form &operator=(const Form &FormPoint); //--> Copy assignment operator 
	~Form();// destructor

/*---------------------------------------------------------------------------------*/
/*			        Form member functions :								           */
/*---------------------------------------------------------------------------------*/

    Form(const std::string& s,const int &gradeS, const int &gradeE);
	std::string getName()const;
	bool getIsSigned ()const;
	int getGradeSigned()const;
	int getGradeExecuted()const;
	void beSigned(Bureaucrat &bureaucrat);
/*---------------------------------------------------------------------------------*/
/*	    		                Form class :			              			   */
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

std::ostream& operator<<(std::ostream& os, const Form& Form);

#include "Bureaucrat.hpp"
#endif