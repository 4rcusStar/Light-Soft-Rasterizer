//
// Created by ASUS on 2026/4/7.
//

#ifndef SOFTRASTERIZER_LIGHT_H
#define SOFTRASTERIZER_LIGHT_H
#include "../math/Vector3f.hpp"

struct Light
{
    Vector3f pos{-5,-5,4};
    float intensity{6};
    Light()=default;
    Light(Vector3f pos,float intensity):pos(pos),intensity(intensity){}
};
#endif //SOFTRASTERIZER_LIGHT_H