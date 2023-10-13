#include "AForm.hpp"


/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical AForm :    						   */
/*-----------------------------------------------------------------------------*/

AForm::AForm():name("someone"), iSsigned(false), GradeSigned(false), GradeExecuted(false){
}

AForm::AForm(const AForm &Aform)
:name(Aform.name), iSsigned(Aform.iSsigned),
	GradeSigned(Aform.GradeSigned), GradeExecuted(Aform.GradeExecuted){
}

AForm& AForm::operator=(const AForm &Aform){
	if (this != &Aform)
	{
		static_cast<std::string>(this->name) = Aform.name;
		this->iSsigned = Aform.iSsigned;
	}
	return *this;
}

AForm::~AForm() {
}

/*-------------------------------------------------------------------------------------*/
/*			                    AForm member functions :								   */
/*-------------------------------------------------------------------------------------*/

AForm::AForm(const std::string& s,const int &gradeS, const int &gradeE):
name(s), iSsigned(false) ,GradeSigned(gradeS), GradeExecuted(gradeE){
	if (gradeS > 150 || gradeE > 150)
		throw GradeTooLowException();
	else if (gradeS < 1 || gradeE < 1)
		throw GradeTooHighException();

}

std::string AForm::getName()const{
	return name;
}
bool AForm::getIsSigned  ()const{
	return iSsigned;
}

int AForm::getGradeSigned()const{
	return GradeSigned;
}

int AForm::getGradeExecuted()const{
	return GradeExecuted;
}


void AForm::beSigned(Bureaucrat &bureaucrat){
	if (getGradeSigned() > 150)
		throw GradeTooLowException();
	else if (getGradeExecuted() < 1)
		throw GradeTooHighException();
	else if (bureaucrat.getGrade() <= getGradeSigned())
		iSsigned = true;
	else
		throw GradeTooLowException();
}

/*-----------------------------------------------------------------------------------------------------*/
/*	    		                             AForm class :			              			           */
/*-----------------------------------------------------------------------------------------------------*/

const char* AForm::GradeTooLowException::what() const throw(){
	return "The AForm Grade is Too Low !!";
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "The AForm Grade is Too Hight !!";
}


const char* AForm::FormNotSingeException::what() const throw(){
	return "The AForm Not singed !!";
}
/*-------------------------------------------------------------------------------------------------------*/
