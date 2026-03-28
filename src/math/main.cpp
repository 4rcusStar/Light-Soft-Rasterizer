//
// Created by ASUS on 2026/3/28.

#include <iostream>
#include "Matrix4f.h"
#include "Vector3f.hpp"
int main()
{
    Matrix4f mat4{
        1,3,5,7,
        2,3,5,8,
        3,7,9,10,
        2,3,3,3
    };
    mat4*=mat4;
    for (int i{0};i<16;++i)
    {
        std::cout<<mat4.at(i)<<" ";
    }
}
