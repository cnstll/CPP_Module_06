#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <stdint.h>
#include <iostream>
#pragma pack(push, 1)

/*
 *  #pragma pack instructs the compiler to pack structure members with particular alignment.
 *  source:  https://stackoverflow.com/questions/3318410/pragma-pack-effect   
*/

struct Data {

    int i1;
    int i2;
    char    c1;
    float   f1;
    float   f2;
};

#pragma pack(pop) 
#endif