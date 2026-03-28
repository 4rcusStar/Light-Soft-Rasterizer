#pragma once
#include <iostream>
#include "Vector3f.hpp"
class Vector4f
{
public:
    float x, y, z, w;
    Vector4f(float x, float y, float z,float w);
    Vector4f(const Vector3f& v3,float w);
    Vector4f operator+(const Vector4f &other) const;
    Vector4f operator-(const Vector4f &other) const;
    Vector4f operator * (float scalar) const;
    Vector4f operator / (float scalar) const;
    Vector4f& operator+=(const Vector4f& other);
    Vector4f& operator*=(float scalar);
    Vector4f& operator-=(const Vector4f& other);
    Vector4f &operator/=(float scalar);

    [[nodiscard]] Vector4f normalized() const;

    [[nodiscard]] float dot(const Vector4f &other) const;
    [[nodiscard]] float length() const;
    friend std::ostream &operator<<(std::ostream &os, const Vector4f &v);
};

inline std::ostream &operator<<(std::ostream &os, const Vector4f &v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z <<", "<< v.w << ")";
    return os;
}
inline Vector4f operator*(float scalar, const Vector4f &v)
{
    return v * scalar;
}

