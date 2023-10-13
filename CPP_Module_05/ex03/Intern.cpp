#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

 Intern:: Intern():name("someone"), Rang(Rang >= 1 && Rang <= 150){
		std::cout <<" Intern " << "default constructor called :)" << std::endl;
}

 Intern:: Intern(const  Intern & Intern){
    *this =  Intern; // Copy the name
    std::cout << " Intern copy constructor called :)" << std::endl;
}

 Intern&  Intern::operator=(const  Intern & Intern){
	if (this != & Intern)
	{
		this->operator=(Intern);
	}
	return *this;
}

 Intern::~ Intern() {
    std::cout << " Intern " << name << " destroyed!" << std::endl;
}

/*---------------------------------------------------------------------------------*/
/*			         Intern member functions :								   */
/*---------------------------------------------------------------------------------*/



AForm* Intern::makeForm(const std::string &name,const std::string &tr){
	AForm *ret = NULL;
	AForm *ptr_Form[3]  = {new ShrubberyCreationForm(tr), new RobotomyRequestForm(tr), new PresidentialPardonForm(tr)}; 
	std::string names[3] = {"shrubbery creation","robotomy request" ,"presidential pardon"};
	for (size_t i = 0; i < 3; i++){
		if (names[i] == name){
			ret = ptr_Form[i];
			i++;
			if(i >= 3)
				break;
		}
		delete ptr_Form[i];
	}
	if (ret == NULL)
		throw WrongNameException();
	return ret;
}

/*---------------------------------------------------------------------------------*/
/*	    		                Intern class :			              			   */
/*---------------------------------------------------------------------------------*/

const char* Intern::WrongNameException::what() const throw(){
	return "The forma name is wrong !!";
}
