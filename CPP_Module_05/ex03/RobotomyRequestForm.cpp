#include "RobotomyRequestForm.hpp"

/*-----------------------------------------------------------------------------------------------------------------------*/
/*				                         Orthodox Canonical Form :    						       			  	         */
/*-----------------------------------------------------------------------------------------------------------------------*/

RobotomyRequestForm::RobotomyRequestForm():AForm(){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ShrubberyCreation) :AForm(ShrubberyCreation) {
	*this = ShrubberyCreation;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &ShrubberyCreation){
	if (this != &ShrubberyCreation)
	{
		this->operator=(ShrubberyCreation);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}


/*--------------------------------------------------------------------------------------------------------------------------*/
/*			                            RobotomyRequestForm member functions :					                        */
/*--------------------------------------------------------------------------------------------------------------------------*/

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm("Robotomy Request",72,45), target(target){

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if(!getIsSigned())
		throw FormNotSingeException();
	if (executor.getGrade() > 150)
		throw GradeTooLowException();
	else if (executor.getGrade() < 1)
		throw GradeTooHighException();
	else if (executor.getGrade() > getGradeSigned())
		throw "The FORM is not signed ,the grade isn't high enough";

    std::srand(static_cast<unsigned int>(time(NULL)));
    int randomNum = std::rand() % 2;
    if( randomNum  == 1)
        std::cout << target << " has been robotomized successfully." <<std::endl;
    else
        std::cout << target << " the robotomy failed." <<std::endl;
}