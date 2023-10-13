#ifndef AFORM_CPP
#define AFORM_CPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdexcept>

class Bureaucrat;
class AForm{
private:
	std::string name;
	bool iSsigned;
	const int GradeSigned;
	const int GradeExecuted;
public:

/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical AForm :    							   */
/*-----------------------------------------------------------------------------*/

	AForm(); // ---> default constructor
	AForm(const AForm &AFormPoint); // ---> copy constructor 
	AForm &operator=(const AForm &AFormPoint); //--> Copy assignment operator 
	virtual ~AForm();// destructor

/*---------------------------------------------------------------------------------*/
/*			        AForm member functions :								           */
/*---------------------------------------------------------------------------------*/

    AForm(const std::string& s,const int &gradeS, const int &gradeE);
	std::string getName()const;
	bool getIsSigned ()const;
	int getGradeSigned()const;
	int getGradeExecuted()const;
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;

/*---------------------------------------------------------------------------------*/
/*	    		                AForm class :			              			   */
/*---------------------------------------------------------------------------------*/

	class GradeTooLowException :public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
	class FormNotSingeException : public std::exception{
	public:
		virtual const char* what() const throw();
	};
/*-------------------------------------------------------------------------------*/
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#include "Bureaucrat.hpp"
#endif