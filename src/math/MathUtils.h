//
// Created by ASUS on 2026/4/2.
//

#ifndef SOFTRASTERIZER_MATHUTILS_H
#define SOFTRASTERIZER_MATHUTILS_H
#include <array>
#include "Vector2f.h"

class MathUtils
{
    //TODO:创建重心插值函数
    ///
    /// @param v 要插值的坐标
    /// @param a A点
    /// @param b B点
    /// @param c C点
    /// @return array{alpha,beta,gamma}
public:
    [[nodiscard]]static std::array<float,3> getBarycentricCoord(const Vector2f& v,const Vector2f& a,const Vector2f& b,const Vector2f& c)
    {
        float alpha;
        float beta;
        float gamma;

        alpha = (-(v.x-b.x)*(c.y-b.y)+(v.y-b.y)*(c.x-b.x))/(-(a.x-b.x)*(c.y-b.y)+(a.y-b.y)*(c.x-b.x));
        beta = (-(v.x-c.x)*(a.y-c.y)+(v.y-c.y)*(a.x-c.x))/(-(b.x-c.x)*(a.y-c.y)+(b.y-c.y)*(a.x-c.x));
        gamma = 1-alpha-beta;
        return {alpha,beta,gamma};
    }
};


#endif //SOFTRASTERIZER_MATHUTILS_H