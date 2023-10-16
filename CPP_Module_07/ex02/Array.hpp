#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
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
    
    Array(const Array &NArray) : length(NArray.length) {
        array = new T[length];
        for (size_t i = 0; i < length; i++)
            array[i] = NArray.array[i];
    }

    Array &operator=(const Array &NArray) {
        if (this == &NArray)
            return *this;
        delete[] array;

        length = NArray.length;
        array = new T[length];
        for (size_t i = 0; i < length; i++)
            array[i] = NArray.array[i];
        return *this;
    }
        
    void putArray(T arr , size_t i){
        if (i < length)
            array[i] = arr;
        else
            throw std::runtime_error("Index out of bounds");
    }

    size_t size() const{
        return length;
    }
    ~Array(){
        delete[] array;
    }

    T& operator[](size_t index) {
        if (index >= 0 && index < length) {
            return array[index];
        } else 
            throw std::runtime_error("Index out of bounds");
}
};

#endif