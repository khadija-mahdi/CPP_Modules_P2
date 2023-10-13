#include "easyfind.hpp"

int main(){
    std::vector<int> v;
    for (int i = 1; i <= 5; i++)
        v.push_back(i);
    try{
        easyfind(v, 5);
        easyfind(v, 2);
        easyfind(v, 9);
    }
    catch(std::exception const& e){
        std::cout << e.what() << std::endl;
    }
}