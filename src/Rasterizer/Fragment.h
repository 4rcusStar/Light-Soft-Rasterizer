#pragma once
#include "../math/Vector2f.h"

struct Fragment
{
    int x{0},y{0};
    float depth{1.0f};

    //重心坐标插值后的属性:
    Vector3f color{255};
    Vector2f texCoord{0,0};
    Vector3f normal{0,0,1};
    Vector3f worldPosition{0,0,0};
    //float alpha;//透明度
    Fragment(int x,int y,float depth,Vector3f color, Vector2f texCoord, Vector3f normal,Vector3f worldPosition):x(x),y(y),depth(depth),color(color),texCoord(texCoord),normal(normal),worldPosition(worldPosition)
    {
    }
    Fragment()=default;
};
