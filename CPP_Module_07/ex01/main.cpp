#include "iter.hpp"

int main(){

    std::cout << "\n-------------- integer type !---------" << std::endl;

    int IntArray[] ={0, 1, 2, 3, 4};
    iter(IntArray, 4,printElements<int>);

    std::cout << "\n-------------- string type !---------" << std::endl;

    std::string StringArray[] = {"Hello", "Hey", "Good Morning", "Bonjour"};
    iter(StringArray, 4,printElements<std::string>);
    
    std::cout << "\n-------------- double type !---------" << std::endl;
    double doubleArray[] ={0.77 , 1.88 , 2.99 , 3.11 , 4.46};
    iter(doubleArray, 4,printElements<double>);
}

// class Awesome
// {
//     public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//     private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main() {
// int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
//     Awesome tab2[5];
//     iter( tab, 5, print );
//     iter( tab2, 5, print );
// return 0;
// }