//
// Created by ASUS on 2026/3/30.
//

#include "Triangle.h"

Triangle::Triangle(Vertex v1, Vertex v2, Vertex v3):v1(v1),v2(v2),v3(v3){};
Triangle::Triangle(Vector3f vec1, Vector3f vec2, Vector3f vec3):v1(Vertex(vec1)),v2(Vertex(vec2)),v3(Vertex(vec3)){}
bool Triangle::isInside(size_t x, size_t y) const
{
    return Triangle::isInside({static_cast<float>(x),static_cast<float>(y)});
};
bool Triangle::isInside(Vector2f coord) const
{
    float a{(coord-v3.screenPosition).cross(v1.screenPosition-v3.screenPosition)};
    float b{(coord-v1.screenPosition).cross(v2.screenPosition-v1.screenPosition)};
    float c{(coord-v2.screenPosition).cross(v3.screenPosition-v2.screenPosition)};
    return (a>=0&&b>=0&&c>=0)||(a<=0&&b<=0&&c<=0);
}

