#include "MutantStack.hpp"

int main()
{
    MutantStack<std::string> mstack;
    mstack.push("helo");
    mstack.push(" it's me ");
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(" i ");
    mstack.push(" love ");
    mstack.push(" you ");
    //[...]
    mstack.push(" but ");
    MutantStack<std::string>::iterator it = mstack.begin();
    MutantStack<std::string>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<std::string> s(mstack);
    return 0;
}