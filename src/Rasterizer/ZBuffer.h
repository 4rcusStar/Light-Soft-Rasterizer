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
    const float _maxDepth{1.f};
public:
    ZBuffer(size_t width, size_t height);
    void clear();
    float& operator()(int x,int y);
};


#endif //SOFTRASTERIZER_ZBUFFER_H