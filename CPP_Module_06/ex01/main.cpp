#include "Serializer.hpp"

int main(){
    Data* data = new Data(1337,42,"ME",13.37);

    uintptr_t ser = Serializer::serialize(data);
    Data* des = Serializer::deserialize(ser);
    std::cout << "the ser values : nbr = " << des->nbr << " , raw = " 
    << des->raw << ", name = " << des->name << " , a = " << des->a << std::endl; 
    delete data;
}