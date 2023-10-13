#include "Span.hpp"

int main(){
    Span sp = Span(5);
    try{
        // sp.addNumbers(0);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    }
    catch(std::exception const& e){
        std::cout << e.what() << std::endl;
    }
    sp.printSpan();
    try{
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception const& e){
        std::cout << e.what() << std::endl;
    }
}


