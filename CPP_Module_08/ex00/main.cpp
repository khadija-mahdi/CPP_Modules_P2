#include "easyfind.hpp"
#include <vector>
#include <set>


int main(){
    std::vector<char> v;
    for (int i = 'H'; i <= 'N'; i++)
        v.push_back(i);
    try{
        easyfind(v, 'H');
        easyfind(v, 'K');
        easyfind(v, 'l');
    }
    catch(std::exception const& e){
        std::cout << e.what() << std::endl;
    }
    std::set<int> s;
    for (int i = 1; i <= 5; i++)
        s.insert(i);
    try{
        easyfind(s, 1);
        easyfind(s, 2);
        easyfind(s, 4);
    }
    catch(std::exception const& e){
        std::cout << e.what() << std::endl;
    }

}

 