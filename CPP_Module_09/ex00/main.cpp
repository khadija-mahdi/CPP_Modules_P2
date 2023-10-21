#include "BitcoinExchange.hpp"


bool checkForm(std::string &value, char c, int flag){
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
            {
                std::string inp = "Error: bad input => " + value + ".";
                throw std::runtime_error(inp);
            }
            return 0;
        }
    }
    return 1;
}

float getValue(std::string &value){
   if (!checkForm(value, '.', 1))
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

void cpyData(std::map<std::string, float> &btcData){
    std::fstream dataFile("data.csv");
    if (dataFile.is_open()){
        std::string line;
        while (std::getline(dataFile, line, '\n')){
            int pos = line.find(',');
            std::string value = line.substr(pos + 1, '\n');
            std::string key =  line.substr(0, pos);;
            float floatValue = getValue(value);
            if (floatValue != -1)
                btcData[key] = floatValue;
        }
        dataFile.close();
    }
	else{
		std::cout << "Error: could not open file." << std::endl;
		exit (1);
	}

}


void checkInput(char *inputF)
{
    int j = 0;
    std::fstream inputFile(inputF);
    if (inputFile.is_open()){

    std::string line;
    while (std::getline(inputFile, line, '\n')){
        j++;
        if (j == 1 && line != "date | value")
        {
            std::string inp = "Error: bad input => " + line + ".";
            std::cout << inp << std::endl;
        }
        int pos = line.find('|');
        std::string date =  line.substr(0, pos);
        std::string value = line.substr(pos + 1, '\n');
        }
        inputFile.close();
    }
	else{
		std::cout << "Error: could not open file." << std::endl;
		exit (1);
	}
}

int main(int ac, char **av){
    if (ac != 2) 
        std::cout << "Error: could not open file." << std::endl;
    else
    {
        std::map<std::string, float> Data;
        cpyData(Data); 
        // for (std::map<std::string, float>::const_iterator it = Data.begin(); it != Data.end(); ++it) {
        //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        // }
        checkInput(av[1]);

    }
    
}