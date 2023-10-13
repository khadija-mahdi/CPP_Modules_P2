#include "ScalarConverter.hpp"

void isInteger(const std::string &str) {
    int intValue;
    std::istringstream intStream(str);
    intStream >> intValue;

    char charValue;
    std::istringstream charStream(str);
    charStream >> charValue;
    try
    {
        if (!intStream.fail())
            std::cout <<"int: "<< static_cast<int>(intValue)<< std::endl;
        else if (!charStream.fail() && str.length() == 1)
            std::cout <<"int: "<< static_cast<int>(charValue)<< std::endl;
        else
            throw ("int: impossible");
    }
    catch (char const*s)
    {
        std::cout << s <<std::endl;
    }
}

void isFloat(const std::string &str) {
    if(str == "nan" || str == "-inf" || str == "+inf")
    {
        std::cout <<"float: "<< str << "f" << std::endl;
        return;
    }
    char charValue;
    std::istringstream charStream(str);
    charStream >> charValue;
    float floatValue;
    std::istringstream floatStream(str);
    floatStream >> floatValue;
    try{
        if (!floatStream.fail())
        {
            if( floatValue == static_cast<int>(floatValue))
            {
                std::cout <<"float: "<< std::fixed << std::setprecision(1) 
                << static_cast<float>(floatValue) << "f" << std::endl;
            }
            else        
                std::cout <<"float: "<< static_cast<float>(floatValue) << "f" << std::endl;
        }
        else if (!charStream.fail() && str.length() == 1)
        {
                std::cout <<"float: "<< std::fixed << std::setprecision(1) 
                << static_cast<float>(charValue) << "f" << std::endl;
        }
        else
            throw ("float: impossible");
    }
    catch (char const*s)
    {
        std::cout << s <<std::endl;
    }
}

void isDouble(const std::string &str) {
    if(str == "nan" || str == "-inf" || str == "+inf")
    {
        std::cout <<"double: "<< str  << std::endl;
        return;
    }
    char charValue;
    std::istringstream charStream(str);
    charStream >> charValue;
    double doubleValue;
    std::istringstream doubleStream(str);
    doubleStream >> doubleValue;
    try
    {
        if (!doubleStream.fail()) {
            double d = static_cast<double>(doubleValue);
            std::cout <<"double: "<< d << std::endl;
        } 
        else if (!charStream.fail()&& str.length() == 1)
            std::cout <<"double: "<< static_cast<double>(charValue) << std::endl;
        else
            throw ("double: impossible");
    }
    catch (char const*s)
    {
        std::cout << s <<std::endl;
    }   
}

void isChar(const std::string &s) {
    char str = s[0];
    try
    {   double Value;
        std::istringstream intStream(s);
        intStream >> Value;
        if (Value >= 0 && Value <= 127)
        {
            if (!intStream.fail() && std::isprint(static_cast<unsigned char>(Value)))
                std::cout <<"char: '"<< static_cast<char>(Value) << "'"<< std::endl;
            else if(std::isalpha(str) && s.length() == 1)
                    std::cout <<"char: '"<< static_cast<char>(str) << "'" << std::endl;
            else if (!std::isprint(static_cast<unsigned char>(Value)))
                throw ("char: Non displayable");
            else
                throw ("char: impossible");
        }
        else
            throw ("char: impossible");
    }
    catch (char const*s)
    {
        std::cout << s <<std::endl;
    }   
}

