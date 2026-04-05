//
// Created by ASUS on 2026/3/30.
//
#ifndef SOFTRASTERIZER_TRIANGLE_H
#define SOFTRASTERIZER_TRIANGLE_H
#include "Vertex.h"

struct Triangle
{
    Vertex v1, v2, v3;
    Triangle(Vertex v1, Vertex v2, Vertex v3);
    Triangle(Vector3f vec1,Vector3f vec2,Vector3f vec3);
    Triangle()=default;
    [[nodiscard]] bool isInside(float x,float y) const;
    [[nodiscard]] bool isInside(Vector2f coord) const;

    ///
    /// @return 以minX,minY,maxX,maxY的顺序返回boundingBox边界
    [[nodiscard]] std::array<float,4> getBoundingBox() const;

    ///
    /// @param coord 要插值的屏幕空间坐标
    /// @return array{alpha,beta,gamma}
    [[nodiscard]] std::array<float, 3> getBarycentric(Vector2f coord) const;
    [[nodiscard]] std::array<float, 3> getBarycentric(float x,float y) const;
    [[nodiscard]] const Vertex& operator[](int index)const
    {
        switch (index)
        {
            case 0:return v1;
            case 1:return v2;
            case 2:return v3;
            default:throw "Invalid index";
        }
    }
    [[nodiscard]] Vertex& operator[](int index)
    {
        switch (index)
        {
            case 0:return v1;
            case 1:return v2;
            case 2:return v3;
            default:throw "Invalid index";
        }
    }
};
#endif //SOFTRASTERIZER_TRIANGLE_H