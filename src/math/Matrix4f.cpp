#include "Matrix4f.h"
Matrix4f  Matrix4f::operator+(const Matrix4f& other) const
{
     Matrix4f result;
    for (int i{0};i<16;++i)
    {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}
Matrix4f Matrix4f::operator-(const Matrix4f& other) const
{
    Matrix4f result;
    for (size_t i = 0; i < 16; ++i)
    {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}
Matrix4f Matrix4f::operator*(const Matrix4f& other) const
{
    Matrix4f result;

    // 行0
    result(0,0) = data[0]*other(0,0) + data[1]*other(1,0) + data[2]*other(2,0) + data[3]*other(3,0);
    result(0,1) = data[0]*other(0,1) + data[1]*other(1,1) + data[2]*other(2,1) + data[3]*other(3,1);
    result(0,2) = data[0]*other(0,2) + data[1]*other(1,2) + data[2]*other(2,2) + data[3]*other(3,2);
    result(0,3) = data[0]*other(0,3) + data[1]*other(1,3) + data[2]*other(2,3) + data[3]*other(3,3);

    // 行1
    result(1,0) = data[4]*other(0,0) + data[5]*other(1,0) + data[6]*other(2,0) + data[7]*other(3,0);
    result(1,1) = data[4]*other(0,1) + data[5]*other(1,1) + data[6]*other(2,1) + data[7]*other(3,1);
    result(1,2) = data[4]*other(0,2) + data[5]*other(1,2) + data[6]*other(2,2) + data[7]*other(3,2);
    result(1,3) = data[4]*other(0,3) + data[5]*other(1,3) + data[6]*other(2,3) + data[7]*other(3,3);

    // 行2
    result(2,0) = data[8]*other(0,0) + data[9]*other(1,0) + data[10]*other(2,0) + data[11]*other(3,0);
    result(2,1) = data[8]*other(0,1) + data[9]*other(1,1) + data[10]*other(2,1) + data[11]*other(3,1);
    result(2,2) = data[8]*other(0,2) + data[9]*other(1,2) + data[10]*other(2,2) + data[11]*other(3,2);
    result(2,3) = data[8]*other(0,3) + data[9]*other(1,3) + data[10]*other(2,3) + data[11]*other(3,3);

    // 行3
    result(3,0) = data[12]*other(0,0) + data[13]*other(1,0) + data[14]*other(2,0) + data[15]*other(3,0);
    result(3,1) = data[12]*other(0,1) + data[13]*other(1,1) + data[14]*other(2,1) + data[15]*other(3,1);
    result(3,2) = data[12]*other(0,2) + data[13]*other(1,2) + data[14]*other(2,2) + data[15]*other(3,2);
    result(3,3) = data[12]*other(0,3) + data[13]*other(1,3) + data[14]*other(2,3) + data[15]*other(3,3);

    return result;
}
Matrix4f Matrix4f::operator*(float scalar) const
{
    Matrix4f result;
    for (int i = 0; i < 16; ++i)
    {
        result(i)=data[i]*scalar;
    }
    return result;
}
Matrix4f& Matrix4f::operator+=(const Matrix4f& other)
{
    *this = *this + other;
    return *this;
}
Matrix4f& Matrix4f::operator-=(const Matrix4f& other)
{
    *this = *this - other;
    return *this;
}
Matrix4f& Matrix4f::operator*=(const Matrix4f& other)
{
    *this=(*this)*other;
    return *this;
}
Matrix4f& Matrix4f::operator*=(float scalar)
{
    *this = *this * scalar;
    return *this;
}

const float& Matrix4f::operator()(int m, int n)const
{
    return data[m*4+n];
}
const float& Matrix4f::operator()(int index)const
{
    return data[index];
}

float & Matrix4f::operator()(int m, int n)
{
    return data[m*4+n];
}

float & Matrix4f::operator()(int index)
{
    return data[index];
}

float Matrix4f::at(int index) const
{
    return data[index];
}

///
/// @param x 第m行
/// @param y 第n列
/// @return 第m行第n列的数字
float Matrix4f::at(int m,int n) const
{
    return data[(m*4+n)];
}
