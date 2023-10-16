#include "Array.hpp"


int main(){

    Array <std::string> StrArray(6);
    // /* 
    std::cout << "\n----- deep copy test ------\n" << std::endl;
    Array <std::string> Str(6);
    {
        // StrArray.putArray("test", 0); // copy contractor
        Array <std::string> str2(StrArray);
        Str =  str2;  // copy assignment
    }
    std::cout << Str[0] << std::endl;
    // */
    std::cout << "\n----- String Type ------\n" << std::endl;
    try
    { 
        for (size_t i = 0; i < StrArray.size() ;i++)
        {
            StrArray.putArray("hello", i);
            std::cout << StrArray[i] << std::endl;
        }
    }
    catch(char const *e)
    {
        std::cerr << e << '\n';
    }

    std::cout << "\n----- Integer Type ------\n" << std::endl;
    
    Array <int> IntArray(6);
    try
    {  
        for (size_t i = 0; i < IntArray.size() ;i++)
        {
            // IntArray.putArray(42 , i);
            std::cout << IntArray[i] << std::endl;
        }
    }
    catch(char const *e)
    {
        std::cerr << e << '\n';
    }

    std::cout << "\n----- double Type ------\n" << std::endl;
    
    Array <double> DoubleArray(6);
    try
    {  
        for (size_t i = 0; i < DoubleArray.size() ;i++)
        {
            // DoubleArray.putArray(13.37, i);
            std::cout << DoubleArray[i] << std::endl;
        }
    }
    catch(char const *e)
    {
        std::cerr << e << '\n';
    }
    // system("leaks Array");
}
