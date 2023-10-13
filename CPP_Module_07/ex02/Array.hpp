#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T> // template prefix;
class Array{
private:
    T *array;
    size_t length;
public:
    Array():length(0){
        array = NULL;
    }
    
    Array(unsigned int n):length(n){
        array = new T[n];
        for(unsigned int i = 0; i < n; i++){
            array[i] = T();
        }
    }
    
    Array(const Array &NArray){
        delete array;
        this->array = new T[NArray.length];
        for(size_t i = 0; i < length; i++)
            this->array[i] = NArray.array[i];
        this->length = NArray.length;
        *this = NArray;
    }
    
    Array &operator=(const Array &NArray){
        if(*this != &NArray){
            delete array;
            this->array = new T[NArray.length];
            for(size_t i = 0; i < length; i++)
                this->array[i] = NArray.array[i];
            this->length = NArray.length;
        }
        return *this;
    }
    
    void printArray() {
        for (size_t i = 0; i < length; i++)
            std::cout << array[i] << std::endl;
    }
    void putArray(T arr , size_t i){
        if (i < length)
        {
            array[i] = arr;
        }
        else
            throw ("out of range");
    }
    size_t size() const{
        return length;
    }
    ~Array(){
        delete[] array;
    }
};

#endif