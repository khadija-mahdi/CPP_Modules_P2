#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



std::ostream& operator <<(std::ostream& os, const Bureaucrat& bureaucrat){
    os <<  bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

std::ostream& operator <<(std::ostream& os, const AForm& AForm){
	os <<  AForm.getName() << ",grade singed is : " << AForm.getGradeSigned() 
	   << ", Executed singed is : " << AForm.getGradeExecuted() 
	   << ", Is signed: " << (AForm.getIsSigned() ? "True" : "False");
	return os;
}

int main() {
    Bureaucrat bureaucrat("kmahdi", 25);
	Intern someRandomIntern;
	AForm *form = NULL;
	try {
			form = someRandomIntern.makeForm("shrubbery creation", "Bender");
			form->beSigned(bureaucrat);
			form->execute(bureaucrat);
			// form = someRandomIntern.makeForm("robotomy request", "Bender");
			// form = someRandomIntern.makeForm("presidential pardon", "Bender");
			std::cout << bureaucrat << std::endl;
			form->beSigned(bureaucrat);
			bureaucrat.signForm(*form);
			std::cout << *form << std::endl;

    }	
	catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	delete form;
    return 0;
}
