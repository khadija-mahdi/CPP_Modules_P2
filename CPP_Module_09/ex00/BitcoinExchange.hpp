#ifndef BICOINEXCHANGE_HPP
#define BICOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <time.h>

class BitcoinExchange{
    std::map<std::string, float> Data;
public:
/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical Form :    							   */
/*-----------------------------------------------------------------------------*/

	BitcoinExchange(); // ---> default constructor
	BitcoinExchange(const BitcoinExchange &BitcoinExchange); // ---> copy constructor 
	BitcoinExchange &operator=(const BitcoinExchange &BitcoinExchange); //--> Copy assignment operator 
	~BitcoinExchange();// destructor

/*-------------------------------------------------------------------------------*/
    void throwEx(std::string &line);
    bool checkForm(std::string &value, char c, int flag , std::string &line);
    float getValue(std::string &value, std::string &line);
    void cpyData();
    float checkValueForm(std::string &value, std::string &line);
    int countUnder(std::string &date);
    std::string checkDateForm(std::string &date, std::string &line);
    void checkInput(char *inputF);
};

#endif