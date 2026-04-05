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
    Vector4f operator*(const Vector4f& other) const;
    Matrix4f operator*(float scalar) const;
    Matrix4f& operator+=(const Matrix4f& other);
    Matrix4f& operator-=(const Matrix4f& other);
    Matrix4f& operator*=(const Matrix4f& other);
    Matrix4f& operator*=(float scalar);
    const float& operator() (int m,int n) const;
    const float& operator() (int index) const;
    float& operator()(int m,int n);
    float& operator()(int index);
    [[nodiscard]] static Matrix4f Identity();
    [[nodiscard]] Matrix4f Inverse();

    /// 计算3阶行列式
    /// @return
    [[nodiscard]] static float determinant3(float a00,float a01,float a02,
                                            float a10,float a11,float a12,
                                            float a20,float a21,float a22);
    /// 计算该矩阵行列式
    /// @return
    [[nodiscard]] float determinant() const;
    void transpose();
    [[nodiscard]]Matrix4f transposed() const;
    static Matrix4f& transpose(Matrix4f& mat);
};
inline Matrix4f operator*(const float scalar,const Matrix4f& mat)
{
    return mat*scalar;
}


