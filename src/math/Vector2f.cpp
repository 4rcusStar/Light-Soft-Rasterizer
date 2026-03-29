#include "Vector2f.h"
#include <cmath>

Vector2f::Vector2f(float x, float y):x(x),y(y){}

Vector2f::Vector2f(float xy):Vector2f(xy,xy)
{

}

Vector2f::Vector2f()=default;

Vector2f Vector2f::operator+(const Vector2f &other) const
{
    return {x+other.x,y+other.y};
}

Vector2f Vector2f::operator-(const Vector2f &other) const
{
    return {x-other.x,y-other.y};
}

Vector2f Vector2f::operator*(float scalar) const
{
    return {x*scalar,y*scalar};
}

Vector2f Vector2f::operator/(float scalar) const
{
    return {x/scalar,y/scalar};
}

Vector2f & Vector2f::operator+=(const Vector2f &other)
{
    *this = *this + other;
    return *this;
}

Vector2f & Vector2f::operator*=(float scalar)
{
    *this = *this * scalar;
    return *this;
}

Vector2f & Vector2f::operator-=(const Vector2f &other)
{
    *this = *this - other;
    return *this;
}

Vector2f & Vector2f::operator/=(float scalar)
{
    *this = *this / scalar;
    return *this;
}

Vector2f Vector2f::normalized() const
{
    return {x/length(),y/length()};
}

float Vector2f::cross(const Vector2f &other) const
{
    return x*other.y-y*other.x;
}

float Vector2f::dot(const Vector2f &other) const
{
    return x*other.x + y*other.y;
}

float Vector2f::length() const
{
    return std::sqrt(x*x + y*y);
}

Vector2f& Vector2f::normalize(Vector2f &v)
{
    v.x/=v.length();
    v.y/=v.length();
    return v;
};
