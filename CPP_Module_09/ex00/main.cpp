#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac != 2) 
        std::cout << "Error: could not open file." << std::endl;
    else
    {
        BitcoinExchange bitcoin;
        bitcoin.cpyData(); 
        bitcoin.checkInput(av[1]);

    }
    
}