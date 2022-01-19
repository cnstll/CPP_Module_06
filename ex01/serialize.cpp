#include "serialize.hpp"
/*
 * "reinterpret_cast only guarantees that if you cast a pointer to a different type,
 * and then reinterpret_cast it back to the original type, you get the original value."
 * source: https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast 
 * source on uintptr: https://stackoverflow.com/questions/1845482/what-is-uintptr-t-data-type 
 */
void    printData(Data *ptr){

    std::cout << "i1: " << ptr->i1 << " - size: "<< sizeof(ptr->i1) << std::endl;
    std::cout << "i2: " << ptr->i2 << " - size: "<< sizeof(ptr->i2) << std::endl;
    std::cout << "c1: " << ptr->c1 << " - size: "<< sizeof(ptr->c1) << std::endl;
    std::cout << "f1: " << ptr->f1 << " - size: "<< sizeof(ptr->f1) << std::endl;
    std::cout << "f2: " << ptr->f2 << " - size: "<< sizeof(ptr->f2) << std::endl;
};

uintptr_t serialize(Data* ptr){

    uintptr_t i = reinterpret_cast<uintptr_t>(ptr);
    return i; 
};

Data* deserialize(uintptr_t raw){

    return (reinterpret_cast<Data*>(raw));
};

int main (void)
{
    uintptr_t serializedData;
    Data ptrIn = { 42, -42, 'a', 42.0f, 3.14f };
    Data *ptrOut;

    std::cout << "Data before serialization: \n";
    printData(&ptrIn);
    std::cout << "Sizeof of Data after deserialization: " << sizeof(ptrIn) << std::endl;
    serializedData = serialize(&ptrIn);
    ptrOut = deserialize(serializedData);
    std::cout << std::endl;
    std::cout << "Data after deserialization: \n";
    printData(ptrOut);
    std::cout << "Sizeof of Data after deserialization: " << sizeof(*ptrOut) << std::endl;
    return 0;
}