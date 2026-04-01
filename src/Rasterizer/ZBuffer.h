//
// Created by ASUS on 2026/4/2.
//

#ifndef SOFTRASTERIZER_ZBUFFER_H
#define SOFTRASTERIZER_ZBUFFER_H
#include<array>
#include <vector>

class ZBuffer
{
private:
    size_t _width, _height;
    std::pmr::vector<float> _data;
    const float _maxDepth{1.0f};
public:
    ZBuffer(size_t width, size_t height);
    void clear();

    /// 将屏幕上x,y坐标的像素深度设置为depth
    /// @param x 屏幕x
    /// @param y 屏幕y
    /// @param depth 深度
    void update(size_t x, size_t y,float depth);
};


#endif //SOFTRASTERIZER_ZBUFFER_H