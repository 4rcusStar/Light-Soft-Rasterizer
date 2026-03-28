#pragma once
#include <array>

#include "Vector4f.h"
#include "Vector3f.hpp"
class Matrix4f
{
public:
    std::array<float,16> data{};
    //默认构造函数为单位矩阵
    Matrix4f()
    {
        data.fill(0);
        data[0]=data[5]=data[10]=data[15]=1;
    };
    Matrix4f(const std::initializer_list<float>& list)
    {
        data.fill(0.0f);
        auto n = std::min(list.size(), data.size());
        std::copy(list.begin(), list.begin() + n, data.begin());
    };

    Matrix4f operator+(const Matrix4f& other) const;
    Matrix4f operator-(const Matrix4f& other) const;
    Matrix4f operator*(const Matrix4f& other) const;
    Matrix4f operator*(float scalar) const;
    Matrix4f& operator+=(const Matrix4f& other);
    Matrix4f& operator-=(const Matrix4f& other);
    Matrix4f& operator*=(const Matrix4f& other);
    Matrix4f& operator*=(float scalar);
    const float& operator() (int m,int n) const;
    const float& operator() (int index) const;
    float& operator()(int m,int n);
    float& operator()(int index);

    [[nodiscard]] float at(int index)const;
    [[nodiscard]] float at(int x,int y)const;
};
inline Matrix4f operator*(const float scalar,const Matrix4f& mat)
{
    return mat*scalar;
}


