#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream& operator <<(std::ostream& os, const Bureaucrat& bureaucrat){
    os <<  bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

std::ostream& operator <<(std::ostream& os, const Form& Form){
	os <<  Form.getName() << ",grade singed is : " << Form.getGradeSigned() 
	   << ", Executed singed is : " << Form.getGradeExecuted() 
	   << ", Is signed: " << (Form.getIsSigned() ? "Yes" : "No");
	return os;
}

int main() {
	try{
    	Bureaucrat bureaucrat("kmahdi", 19);
		Form form("form", 18, 150);
    	try {
				std::cout << bureaucrat << std::endl;
				form.beSigned(bureaucrat);
				bureaucrat.signForm(form);

    	}	
		catch (std::exception& e) {
    	    std::cerr << "Exception: " << e.what() << std::endl;
    	}
		bureaucrat.incrementGrade();
		form.beSigned(bureaucrat);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}