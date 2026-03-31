//
// Created by ASUS on 2026/3/29.
//
#include "Renderer.h"

#include <fstream>

void Renderer::draw()
{
    //没有alpha通道
    std::ofstream ofs("out.ppm",std::ios::binary);
    ofs <<"P6\n"<<_framebuffer.getWidth()<<" "<<_framebuffer.getHeight()<<"\n255\n";
    for (size_t y = 0; y<_framebuffer.getHeight();++y)
    {
        for (size_t x = 0; x<_framebuffer.getWidth();++x)
        {
            std::byte* pixel{_framebuffer.pixel(x,y)};
            ofs.write(reinterpret_cast<char*>(pixel),3);
        }
    }
}

void Renderer::clear()
{
    _framebuffer.clear();
}
