#include "RPN.hpp"

int main(int ac, char **av){
    if (ac != 2) 
        std::cout << "Error" << std::endl;
    else
    {
        RPN RPN;
        try
        {
            RPN.RPNExpression(std::string(av[1]));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    
}