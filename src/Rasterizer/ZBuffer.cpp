//
// Created by ASUS on 2026/4/2.
//

#include "ZBuffer.h"

ZBuffer::ZBuffer(size_t width, size_t height):_width(width),_height(height)
{
    _data.resize(width * height);
    std::fill(_data.begin(), _data.end(), _maxDepth);
}

void ZBuffer::update(size_t x, size_t y, float depth)
{
    _data[y * _width + x] = depth;
}
void ZBuffer::clear()
{
    std::fill(_data.begin(), _data.end(), _maxDepth);
}
