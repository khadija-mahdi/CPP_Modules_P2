#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


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
    try {
        Bureaucrat bureaucrat("kmahdi", 10);
        try{ 
            ShrubberyCreationForm crtForm("home");
            crtForm.beSigned(bureaucrat);
            bureaucrat.signForm(crtForm);
            bureaucrat.executeForm(crtForm);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        try{
            RobotomyRequestForm robForm("noise");
            robForm.beSigned(bureaucrat);
            bureaucrat.signForm(robForm);
            bureaucrat.executeForm(robForm);
        } 
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        try{
            PresidentialPardonForm prsdForm("Zaphod");
            prsdForm.beSigned(bureaucrat); 
            bureaucrat.signForm(prsdForm);
            bureaucrat.executeForm(prsdForm);
        }
		catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
         }

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
