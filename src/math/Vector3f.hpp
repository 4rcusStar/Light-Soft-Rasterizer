#pragma once
#include <iostream>
class Vector4f;
class Vector3f
{
public:
    float x, y, z;
    Vector3f(float x, float y, float z);
    Vector3f(float xyz);
    explicit Vector3f(const Vector4f& v4);
    Vector3f operator+(const Vector3f &other) const;
    Vector3f operator-(const Vector3f &other) const;
    Vector3f operator * (float scalar) const;

    /// 分量相乘
    /// @param other
    /// @return
    Vector3f operator * (Vector3f other)const;
    Vector3f operator / (float scalar) const;
    Vector3f& operator+=(const Vector3f& other);
    Vector3f& operator*=(float scalar);
    Vector3f& operator-=(const Vector3f& other);
    Vector3f &operator/=(float scalar);

    [[nodiscard]] Vector3f normalized() const;
    [[nodiscard]] Vector3f cross(const Vector3f &other) const;
    [[nodiscard]] float dot(const Vector3f &other) const;
    [[nodiscard]] float length() const;
    [[nodiscard]] static Vector3f& normalize(Vector3f& v);
    friend std::ostream &operator<<(std::ostream &os, const Vector3f &v);
};

inline std::ostream &operator<<(std::ostream &os, const Vector3f &v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}
inline Vector3f operator*(float scalar, const Vector3f &v)
{
    return v * scalar;
}
