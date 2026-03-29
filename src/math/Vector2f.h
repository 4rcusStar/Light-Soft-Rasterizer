#pragma once
#include <iostream>
class Vector2f
{
public:
    float x{0},y{0};
    Vector2f();
    Vector2f(float x,float y);
    explicit Vector2f(float xy);
    Vector2f operator+(const Vector2f &other) const;
    Vector2f operator-(const Vector2f &other) const;
    Vector2f operator * (float scalar) const;
    Vector2f operator / (float scalar) const;
    Vector2f& operator+=(const Vector2f& other);
    Vector2f& operator*=(float scalar);
    Vector2f& operator-=(const Vector2f& other);
    Vector2f &operator/=(float scalar);
    [[nodiscard]] Vector2f normalized() const;
    [[nodiscard]] float cross(const Vector2f &other) const;
    [[nodiscard]] float dot(const Vector2f &other) const;
    [[nodiscard]] float length() const;
    [[nodiscard]] static Vector2f& normalize(Vector2f& v);
    friend std::ostream &operator<<(std::ostream &os, const Vector2f &v);
};
inline std::ostream &operator<<(std::ostream &os, const Vector2f &v)
{
    os << "(" << v.x << ", " << v.y<<")";
    return os;
}

