#include "Matrix4f.h"

#include <cmath>
#include <math.h>

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

Vector4f Matrix4f::operator*(const Vector4f &other) const
{
    Vector4f res{0};
    res.x = (*this)(0,0)*other.x+ (*this)(0,1)*other.y+ (*this)(0,2)*other.z+(*this)(0,3)*other.w;
    res.y = (*this)(1,0)*other.x+ (*this)(1,1)*other.y+ (*this)(1,2)*other.z+(*this)(1,3)*other.w;
    res.z = (*this)(2,0)*other.x+ (*this)(2,1)*other.y+ (*this)(2,2)*other.z+(*this)(2,3)*other.w;
    res.w = (*this)(3,0)*other.x+ (*this)(3,1)*other.y+ (*this)(3,2)*other.z+(*this)(3,3)*other.w;
    return res;
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

Matrix4f Matrix4f::Identity()
{
    {
        return
     {
         1,0,0,0,
         0,1,0,0,
         0,0,1,0,
         0,0,0,1
        };
    }
}

Matrix4f Matrix4f::Inverse()
{
}


inline float Matrix4f::determinant3(float a00, float a01, float a02, float a10, float a11, float a12,
    float a20, float a21, float a22)
{
    return a00*(a11*a22-a12*a21)
    -a01*(a10*a22-a12*a20)
    +a02*(a10*a21-a11*a20);
}

float Matrix4f::determinant() const
{
    float s0 = data[10] * data[15] - data[11] * data[14];
    float s1 = data[9]  * data[15] - data[11] * data[13];
    float s2 = data[9]  * data[14] - data[10] * data[13];
    float s3 = data[8]  * data[15] - data[11] * data[12];
    float s4 = data[8]  * data[14] - data[10] * data[12];
    float s5 = data[8]  * data[13] - data[9]  * data[12];

    float c0 = data[5] * s0 - data[6] * s1 + data[7] * s2;
    float c1 = data[4] * s0 - data[6] * s3 + data[7] * s4;
    float c2 = data[4] * s1 - data[5] * s3 + data[7] * s5;
    float c3 = data[4] * s2 - data[5] * s4 + data[6] * s5;
    return data[0] * c0 - data[1] * c1 + data[2] * c2 - data[3] * c3;
}

void Matrix4f::transpose()
{
    Matrix4f copy{*this};
    for (int i{0};i<4;++i)
    {
        for (int j{0};j<4;++j)
        {
            (*this)(i,j)=copy(j,i);
        }
    }
}
Matrix4f Matrix4f::transposed() const
{
    Matrix4f res;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            res(i, j) = (*this)(j, i);
    return res;
}


Matrix4f& Matrix4f::transpose(Matrix4f& mat)
{
    mat.transpose();
    return mat;
}

Matrix4f Matrix4f::rotateX(float radians)
{
    float cosTheta = cos(radians);
    float sinTheta = sin(radians);
    Matrix4f mat = {
        1, 0, 0, 0,
        0, cosTheta, -sinTheta, 0,
        0, sinTheta, cosTheta, 0,
        0, 0, 0, 1
    };
    return mat;
}
