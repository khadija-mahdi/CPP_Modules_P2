#include "Bureaucrat.hpp"


/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

Bureaucrat::Bureaucrat():name("someone"), Grade(15){
	std::cout <<"Bureaucrat " << "default constructor called :)" << std::endl;
	if (Grade> 150)
		throw GradeTooLowException();
	else if (Grade< 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat){
    *this = bureaucrat; // Copy the name
    std::cout << "Bureaucrat copy constructor called :)" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat){
	if (this != &bureaucrat)
	{
		static_cast<std::string>(this->name) = bureaucrat.name;
		this->Grade= bureaucrat.Grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << name << " destroyed!" << std::endl;
}

/*---------------------------------------------------------------------------------*/
/*			        Bureaucrat member functions :								   */
/*---------------------------------------------------------------------------------*/

Bureaucrat::Bureaucrat(const std::string& s, const int &Grade):name(s), Grade(Grade){
	if (Grade> 150)
		throw GradeTooLowException();
	else if (Grade< 1)
		throw GradeTooHighException();
}
std::string Bureaucrat::getName()const{
	return name;
}

int Bureaucrat::getGrade()const{
	return Grade;
}

void  Bureaucrat::decrementGrade(){
	if (Grade< 150)
		Grade+= 1;
	else
		throw GradeTooLowException();
	
}

void  Bureaucrat::incrementGrade(){
	if (Grade> 1)
		Grade-= 1;
	else
		throw GradeTooHighException();
}

void Bureaucrat::signForm(AForm &form){
 	if (form.getIsSigned()  == true)
		std::cout << "bureaucrat signed " << form.getName() <<std::endl;
	else
		std::cout << "bureaucrat couldn’t sign form because the grade isn't high enough" << std::endl;

}

void Bureaucrat::executeForm(const AForm& form) {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

/*-----------------------------------------------------------------------------------------------------*/
/*	    		                             BUREAUCRAT classes :			              			           */
/*-----------------------------------------------------------------------------------------------------*/

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Throwing exception : The Grade is Too Low !!";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Throwing exception : The Grade is Too Hight !!";
}