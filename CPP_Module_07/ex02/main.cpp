#include "Array.hpp"

int main(){
    std::cout << "\n----- String Type ------\n" << std::endl;

    Array <std::string> StrArray(6);
    try
    {  for (int i = 0; i < 6 ;i++)
            StrArray.putArray("hello", i);
    }
    catch(char const *e)
    {
        std::cerr << e << '\n';
    }
    StrArray.printArray();
    std::cout << "\n----- Integer Type ------\n" << std::endl;
    
    Array <int> IntArray(6);
    try
    {  for (int i = 0; i < 9 ;i++)
            IntArray.putArray(42, i);
    }
    catch(char const *e)
    {
        std::cerr << e << '\n';
    }
    IntArray.printArray();

    std::cout << "\n----- double Type ------\n" << std::endl;
    
    Array <double> DoubleArray(6);
    try
    {  for (int i = 0; i < 6 ;i++)
            DoubleArray.putArray(13.37, i);
    }
    catch(char const *e)
    {
        std::cerr << e << '\n';
    }
    DoubleArray.printArray();
}
