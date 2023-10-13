#include "PresidentialPardonForm.hpp"

/*-----------------------------------------------------------------------------------------------------------------------*/
/*				                         Orthodox Canonical Form :    						       			  	         */
/*-----------------------------------------------------------------------------------------------------------------------*/

PresidentialPardonForm::PresidentialPardonForm():AForm(){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ShrubberyCreation) :AForm(ShrubberyCreation) {
	*this = ShrubberyCreation;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ShrubberyCreation){
	if (this != &ShrubberyCreation)
	{
		this->operator=(ShrubberyCreation);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}


/*--------------------------------------------------------------------------------------------------------------------------*/
/*			                            PresidentialPardonForm member functions :					                        */
/*--------------------------------------------------------------------------------------------------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):AForm("Presidential Pardon",25,5), target(target){

}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if(!getIsSigned())
		throw FormNotSingeException();
	if (executor.getGrade() > 150)
		throw GradeTooLowException();
	else if (executor.getGrade() < 1)
		throw GradeTooHighException();
	else if (executor.getGrade() > getGradeSigned())
		throw "The FORM is not signed ,the grade isn't high enough";

    std::cout << target << "has been pardoned by Zaphod Beeblebrox." <<std::endl;
}
