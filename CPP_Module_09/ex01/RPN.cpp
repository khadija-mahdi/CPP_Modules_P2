
#include "RPN.hpp"
/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

RPN::RPN(){
}

RPN::RPN(const RPN &RPN){
	*this = RPN;
}

RPN& RPN::operator=(const RPN &RPN){
	if (this != &RPN)
	{
		this->Data = RPN.Data;
	}
	return *this;
}

RPN::~RPN(){
}
/*------------------------------------------------------------------------------------*/
void RPN::Addition(std::string &value){
    if (value == "+"){
        int first = Data.top();
        Data.pop();
        int secund = Data.top();
        Data.pop();
        std::cout << secund << " + " << first<< " = " << secund + first << std::endl;
        Data.push(secund + first);
        std::cout << Data.top() << std::endl;
    }
}

void RPN::multiplication(std::string &value){
    if (value == "*"){
        int first;
        int secund;
        first = Data.top();
        Data.pop();
        secund = Data.top();
        Data.pop();
        std::cout << secund << " * " << first<< " = " << secund * first << std::endl;
        Data.push(secund * first);
        std::cout << Data.top() << std::endl;
    }
}

void RPN::Subtraction(std::string &value){

    if (value == "-"){
        int first;
        int secund;
        first = Data.top();
        Data.pop();
        secund = Data.top();
        Data.pop();
        std::cout << secund << " - " << first << " = " << secund - first << std::endl;
        Data.push(secund - first);
        std::cout << Data.top() << std::endl;
    }
}

void RPN::Division(std::string &value){
    if (value == "/"){
        int first;
        int secund;
        first = Data.top();
        Data.pop();
        secund = Data.top();
        Data.pop();
        std::cout << secund << " / " << first<< " = " << secund / first << std::endl;
        Data.push(secund / first);
        std::cout << Data.top() << std::endl;
    }
}


void RPN::RPNExpression(std::string expression){
    std::istringstream iss(expression);
    std::string value;

    while (std::getline(iss,value, ' ')) {
        if (value.empty())
            continue;
        if ((std::isdigit(value[0]) && value.size() == 1) 
            || (value [0] == '-' && std::isdigit(value[1]) && value.size() == 2))
        {
            Data.push(std::stoi(value));
            continue;
        }
        else if (!(value == "+" || value == "-" || value == "*" || value == "/"))
            throw std::runtime_error("ERROR"); 
        while(Data.size() >= 2)
        {
            Addition(value);
            Subtraction(value);
            multiplication(value);
            Division(value);
        }

    }
    while (!Data.empty())
    {
        std::cout << Data.top() << " ";
        Data.pop();
    }
}
