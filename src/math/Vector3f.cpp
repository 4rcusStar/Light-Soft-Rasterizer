#include "Vector3f.hpp"
#include "Vector4f.h"
#include <cmath>
Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}
Vector3f::Vector3f(float xyz):Vector3f(xyz,xyz,xyz)
{
};
Vector3f::Vector3f(const Vector4f &v4):x(v4.x),y(v4.y),z(v4.z){};

Vector3f Vector3f::operator+(const Vector3f &other) const
{
    return {x + other.x, y + other.y, z + other.z};
}
Vector3f Vector3f::operator-(const Vector3f &other) const
{
    return {x - other.x, y - other.y, z - other.z};
}
Vector3f Vector3f::operator*(float scalar) const
{
    return {x * scalar, y * scalar, z * scalar};
}
Vector3f Vector3f::operator / (float scalar) const
{
    return {x / scalar, y / scalar, z / scalar};
}
Vector3f& Vector3f::operator+=(const Vector3f& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}
Vector3f& Vector3f::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}
Vector3f& Vector3f::operator-=(const Vector3f& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}
Vector3f& Vector3f::operator/=(float scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}
float Vector3f::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}
Vector3f Vector3f::normalized() const
{
    return {x / length(), y / length(), z / length()};
}
Vector3f Vector3f::cross(const Vector3f &other) const
{
    return {y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x};
}
float Vector3f::dot(const Vector3f &other) const
{
    return x*other.x + y*other.y + z*other.z;
}

Vector3f& Vector3f::normalize(Vector3f& v)
{
    return v/=v.length();
}
