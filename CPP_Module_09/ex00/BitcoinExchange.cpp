#include "BitcoinExchange.hpp"

/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &BitcoinExchange){
	*this = BitcoinExchange;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &BitcoinExchange){
	if (this != &BitcoinExchange)
	{
		this->Data = std::map<std::string, float>(BitcoinExchange.Data.begin(), BitcoinExchange.Data.end());
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
}
/*-------------------------------------------------------------------------------------------*/

void BitcoinExchange::throwEx(std::string &line){
    std::string inp = "Error: bad input => " + line + ".";
    throw std::runtime_error(inp);
}

bool BitcoinExchange::checkForm(std::string &value, char c, int flag , std::string &line){
    int f = 0;
    for (int i = 0; i < value.size(); i++){
        if (value[0] == '-')
        {
            if (flag == 0)
                throw std::runtime_error("Error: not a positive number.");
            return 0;
        }
        if (value[i] == c)
            f++;
        if ((!std::isdigit(value[i]) && value[i] != c) || f > 1)
        {
            if (flag == 0)
                throwEx(line);
            return 0;
        }
    }
    return 1;
}

float BitcoinExchange::getValue(std::string &value, std::string &line){
   if (!checkForm(value, '.', 1, line))
        return -1;
    std::istringstream floatStream(value);
    float floatValue;
    if (floatStream >> floatValue) {
        if (floatStream.fail())
            return -1;
        else if (floatValue >= 0)
            return floatValue;
    }
    return -1;
}

void BitcoinExchange::cpyData(){
    std::fstream dataFile("data.csv");
    if (dataFile.is_open()){
        std::string line;
        while (std::getline(dataFile, line, '\n')){
            int pos = line.find(',');
            std::string value = line.substr(pos + 1, '\n');
            std::string key =  line.substr(0, pos);;
            float floatValue = getValue(value, line);
            if (floatValue != -1)
                Data[key] = floatValue;
        }
        dataFile.close();
    }
	else{
		std::cout << "Error: could not open file." << std::endl;
		exit (1);
	}

}

float BitcoinExchange::checkValueForm(std::string &value, std::string &line){
    float floatValue = -1;
    if (value.size() < 1)
        throwEx(line);
    checkForm(value, '.', 0, line);
    std::istringstream floatStream(value);
    if (floatStream >> floatValue) {
        if (floatStream.fail())
            throwEx(line);
        if (floatValue >= 2147483648)
            throw std::runtime_error("Error: too large a number.");
        else if (floatValue >= 0)
          return floatValue;
    }
    return floatValue;
}

int BitcoinExchange::countUnder(std::string &date){
    
    int len = 0;
    for (int i = 0; date[i] ;i++){
        if (date[i] == '-')
            len++;
        if ((!std::isdigit(date[i]) && date[i] != '-') )
            return -1;
    }
    return len;
}


std::string BitcoinExchange::checkDateForm(std::string &date, std::string &line){
    if (date.size() != 10 || countUnder(date) != 2)
        throwEx(line);
    std::istringstream ss(date);
    std::string years, months, days;

    std::getline(ss, years, '-');
    std::getline(ss, months, '-');
    std::getline(ss, days);

    int year = std::stoi(years);
    int month = std::stoi(months);
    int day = std::stoi(days);
    if (day <= 0 || day > 31 || month < 1 || month > 12 || year < 2009)
        throwEx(line);
    if (year == 2009 && day < 2)
        throwEx(line);
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 13; i++) {
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))){
            if (day > 29)
                throwEx(line);
            continue;
        }
        if (daysInMonth[month] < day)
            throwEx(line);
    }
    return date;
}

void BitcoinExchange::checkInput(char *inputF)
{
    int j = 0;
    std::fstream inputFile(inputF);
    if (inputFile.is_open())
    {
        std::string line;
        while (std::getline(inputFile, line, '\n'))
        {
            if (++j == 1 && line != "date | value")
                std::cout << "Error: bad input => " <<  line  <<  "." << std::endl;
            if (j > 1)
            {
                int pos = line.find('|');
                // -------------- date  | value part -----------------------
            
                if (pos == std::string::npos)
                    std::cout << "Error: bad input => " <<  line  <<  "." << std::endl;

                
                //----------------- date and value ------------------------
    
                std::string date =  line.substr(0, pos - 1);
                std::string value = line.substr(pos + 2, '\n');
                try{
                    std::string formateDate = checkDateForm(date, line);
                    float formateValue = checkValueForm(value, line);
                    std::map<std::string , float>::iterator it = Data.lower_bound(formateDate);
                    if (it != Data.begin())
                        --it;
                    float valu = it->second;
                    std::cout << formateDate  << "=> " << formateValue <<" = " << formateValue * valu << std::endl;
                }
                catch (std::exception const &e)
                {
                    std::cout << e.what() << std::endl;
                }
            }
            
        }
        inputFile.close();
    }
	else{
		std::cout << "Error: could not open file." << std::endl;
		exit (1);
	}
}