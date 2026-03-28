//
// Created by ASUS on 2026/3/28.

#include <iostream>
#include <ostream>

#include "Vector3f.hpp"

int main()
{
    Vector3f vec1{0,1,1};
    Vector3f vec2{4,5,6};
    std::cout << vec1 << std::endl;
    std::cout << vec1.length() << std::endl;
    std::cout << vec1+vec2 << std::endl;
    std::cout << vec1*2 << "," << 2*vec2 << std::endl;
    std::cout << vec1/3<<std::endl;
    std::cout << vec1.dot(vec2) << std::endl;
    std::cout << vec1.cross(vec2) << std::endl;
    std::cout << Vector3f::normalize(vec1) << std::endl;
    std::cout << vec1 << std::endl;
}
