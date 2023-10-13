#include "Bureaucrat.hpp"

std::ostream& operator <<(std::ostream& buffer, const Bureaucrat& bureaucrat){
    buffer <<  bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return buffer;
}

int main() {

    try {
    	Bureaucrat bureaucrat("kmahdi", 21);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
    }
	catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
