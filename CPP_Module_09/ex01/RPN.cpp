
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

void RPN::RPNExpression(char *expression){
    std::istringstream iss(expression);

    for(int i = 0; expression[i]; i++) {
        if (expression[i] == ' ')
            continue;;
        if (std::isdigit(expression[i]))
        {
            Data.push(expression[i] - '0');
            continue;
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            if (Data.size() < 2)
                throw std::runtime_error("ERROR");
            int first;
            int secund;
            first = Data.top();
            Data.pop();
            secund = Data.top();
            Data.pop();
            if (expression[i] == '+')
                Data.push(secund + first);
            else if (expression[i] == '-')
                Data.push(secund - first);
            else if (expression[i] == '*')
                Data.push(secund * first);
            else if (expression[i] == '/')
                Data.push(secund / first);
        }
        else
            throw std::runtime_error("ERROR"); 

    }
    if (Data.size() != 1 )
            throw std::runtime_error("ERROR"); 
    std::cout << Data.top();
}