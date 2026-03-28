//
// Created by ASUS on 2026/3/28.
//

#include "Vector4f.h"

#include <cmath>

Vector4f Vector4f::operator+(const Vector4f &other) const
{
    return {x + other.x, y + other.y, z + other.z, w + other.w};
}
Vector4f Vector4f::operator-(const Vector4f &other) const
{
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}
Vector4f Vector4f::operator*(float scalar) const
{
    return {x * scalar, y * scalar, z * scalar, w * scalar};
}
Vector4f Vector4f::operator / (float scalar) const
{
    return {x / scalar, y / scalar, z / scalar, w / scalar};
}
Vector4f& Vector4f::operator+=(const Vector4f& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}
Vector4f& Vector4f::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}
Vector4f& Vector4f::operator-=(const Vector4f& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}
Vector4f& Vector4f::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}
float Vector4f::length() const
{
    return std::sqrt(x * x + y * y + z * z+w * w);
}
Vector4f Vector4f::normalized() const
{
    return {x / length(), y / length(), z / length(),w / length()};
}
float Vector4f::dot(const Vector4f &other) const
{
    return x*other.x + y*other.y + z*other.z;
}


