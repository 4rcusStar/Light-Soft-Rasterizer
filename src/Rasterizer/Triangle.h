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
    [[nodiscard]] bool isInside(size_t x,size_t y) const;
    [[nodiscard]] bool isInside(Vector2f coord) const;
};
#endif //SOFTRASTERIZER_TRIANGLE_H