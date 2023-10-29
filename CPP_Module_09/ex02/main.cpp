#include "PmergeMe.hpp"

int main(int ac, char **av){
    
    PmergeMe mergeMe;
    try
    {
        mergeMe.setSize(ac - 1);
        mergeMe.mergeInsert(av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
}