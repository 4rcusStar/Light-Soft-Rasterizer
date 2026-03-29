#pragma once
#include "../math/Color.h"
#include "../math/Vector2f.h"

struct Fragment
{
    int x,y;
    float depth;

    //重心坐标插值后的属性:
    Color color;
    Vector2f texCoord;
    Vector3f normal;
    Vector3f worldPosition;
    float alpha;//透明度
    Fragment() : x(0), y(0), depth(1.0f), alpha(1.0f){};
};
