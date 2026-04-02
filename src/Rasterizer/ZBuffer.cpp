//
// Created by ASUS on 2026/4/2.
//

#include "ZBuffer.h"

ZBuffer::ZBuffer(size_t width, size_t height):_width(width),_height(height)
{
    _data.resize(width * height);
    std::fill(_data.begin(), _data.end(), _maxDepth);
}


float& ZBuffer::operator()(int x, int y)
{
    return _data[y * _width + x];
}

void ZBuffer::clear()
{
    std::fill(_data.begin(), _data.end(), _maxDepth);
}
