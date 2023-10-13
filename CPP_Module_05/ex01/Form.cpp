#include "Form.hpp"


/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

Form::Form():name("someone"), iSsigned(false), GradeSigned(false), GradeExecuted(false){
		std::cout <<"Form " << "default constructor called :)" << std::endl;
}

Form::Form(const Form &form)
:name(form.name), iSsigned(form.iSsigned),
	GradeSigned(form.GradeSigned), GradeExecuted(form.GradeExecuted){
    std::cout << "Form copy constructor called :)" << std::endl;
}

Form& Form::operator=(const Form &form){
	if (this != &form)
	{
		static_cast<std::string>(this->name) = form.name;
		this->iSsigned = form.iSsigned;
	}
	return *this;
}

Form::~Form() {
    std::cout << "Form " << name << " destroyed!" << std::endl;
}

/*-------------------------------------------------------------------------------------*/
/*			                    Form member functions :								   */
/*-------------------------------------------------------------------------------------*/

Form::Form(const std::string& s,const int &gradeS, const int &gradeE):
name(s), iSsigned(false) ,GradeSigned(gradeS), GradeExecuted(gradeE){
	if (gradeS > 150 || gradeE > 150)
		throw GradeTooLowException();
	else if (gradeS < 1 || gradeE < 1)
		throw GradeTooHighException();
}

std::string Form::getName()const{
	return name;
}
bool Form::getIsSigned  ()const{
	return iSsigned;
}

int Form::getGradeSigned()const{
	return GradeSigned;
}

int Form::getGradeExecuted()const{
	return GradeExecuted;
}


void Form::beSigned(Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() <= getGradeSigned())
		iSsigned = true;
	else
		throw GradeTooLowException();
}

/*-----------------------------------------------------------------------------------------------------*/
/*	    		                             Form class :			              			           */
/*-----------------------------------------------------------------------------------------------------*/

const char* Form::GradeTooLowException::what() const throw(){
	return "The Grade is Too Low !!";
}

const char* Form::GradeTooHighException::what() const throw(){
	return "The  Grade is Too Hight !!";
}

/*-------------------------------------------------------------------------------------------------------*/
