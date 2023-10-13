#include "iter.hpp"

int main(){

    std::cout << "\n-------------- integer type !---------" << std::endl;

    int IntArray[] ={0, 1, 2, 3, 4};
    iter(IntArray, 4,print<int>);

    std::cout << "\n-------------- string type !---------" << std::endl;

    std::string StringArray[] = {"Hello", "Hey", "Good Morning", "Bonjour"};
    iter(StringArray, 4,print<std::string>);
    
    std::cout << "\n-------------- double type !---------" << std::endl;
    double doubleArray[] ={0.77 , 1.88 , 2.99 , 3.11 , 4.46};
    iter(doubleArray, 4,print<double>);
}
