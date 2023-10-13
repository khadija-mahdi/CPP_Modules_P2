#include "ShrubberyCreationForm.hpp"

/*-----------------------------------------------------------------------------------------------------------------------*/
/*				                         Orthodox Canonical Form :    						       			  	         */
/*-----------------------------------------------------------------------------------------------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm():AForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreation) :AForm(ShrubberyCreation) {
	*this = ShrubberyCreation;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ShrubberyCreation){
	if (this != &ShrubberyCreation)
	{
		this->operator=(ShrubberyCreation);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}


/*--------------------------------------------------------------------------------------------------------------------------*/
/*			                            ShrubberyCreationForm member functions :					                        */
/*--------------------------------------------------------------------------------------------------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm("Shrubbery Creation",145,137), target(target){

}

std::string tree() {
    std::string tree =
    "                                               .\n"
    "                                  .         ;\n"
    "      .              .              ;%     ;;\n"
    "        ,           ,                :;%  %;\n"
    "         :         ;                   :;%;'     .,\n"
    ",.        %;     %;            ;        %;'    ,;\n"
    "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
    "   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
    "    ;%;      %;        ;%;        % ;%;  ,%;'\n"
    "     `%;.     ;%;     %;'         `;%%;.%;'\n"
    "      `:;%.    ;%%. %@;        %; ;@%;%'\n"
    "         `:%;.  :;bd%;          %;@%;'\n"
    "           `@%:.  :;%.         ;@@%;'\n"
    "             `@%.  `;@%.      ;@@%;\n"
    "               `@%%. `@%%    ;@@%;\n"
    "                 ;@%. :@%%  %@@%;\n"
    "                   %@bd%%%bd%%:;\n"
    "                     #@%%%%%:;;\n"
    "                     %@@%%%::;\n"
    "                     %@@@%(o);  . '\n"
    "                     %@@@o%;:(.,'\n"
    "                 `.. %@@@o%::;\n"
    "                    `)@@@o%::;\n"
    "                     %@@(o)::;\n"
    "                    .%@@@@%::;\n"
    "                    ;%@@@@%::;.\n"
    "                   ;%@@@@%%:;;;.\n"
    "               ...;%@@@@@%%:;;;;,..    \n"
    "------------------------------------------------\n"
    "------------------------------------------------"  ;
    return tree;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if(!getIsSigned())
		throw FormNotSingeException();
	if (executor.getGrade() > 150)
		throw GradeTooLowException();
	else if (executor.getGrade() < 1)
		throw GradeTooHighException();
	else if (executor.getGrade() > getGradeSigned())
		throw "The FORM is not signed ,the grade isn't high enough";
	

	std::string  file = std::string(target) + "_shrubbery";
	const char *new_file = file.c_str();
	std::ofstream file_shrubbery(new_file);
	if (file_shrubbery.is_open())
	{
		file_shrubbery << tree() + tree() + tree();
		file_shrubbery.close();
	}
	else
		std::cout << "failed to open" << target << "_shrubbery" << std::endl;
}