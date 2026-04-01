//
// Created by ASUS on 2026/3/29.
//
#include "Renderer.h"

#include <fstream>
void Renderer::setModelMatrix(Matrix4f m){_modelMatrix = m;}
void Renderer::setViewMatrix(Matrix4f v){_viewMatrix = v;}
void Renderer::setProjectionMatrix(Matrix4f p){_projectionMatrix = p;}

void Renderer::addTriangle(const Triangle& tri)
{
    _triangles.push_back(tri);
}

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

void Renderer::nextFrame()
{
    //外层遍历三角形
    for (auto& tri : _triangles)
    {
        std::array boundingBox{tri.getBoundingBox()};
        int minY{static_cast<int>(boundingBox[1])};
        int minX{static_cast<int>(boundingBox[0])};
        int maxX{static_cast<int>(boundingBox[2])};
        int maxY{static_cast<int>(boundingBox[3])};
        for (int y = minY; y<=maxY;++y)
        {
            for (int x = minX; x<=maxX;++x)
            {
                if (tri.isInside(.5f+x,y+.5f))
                {
                    //TODO:使用重心插值表示每个片元的深度。
                    std::byte* pixel {_framebuffer.pixel(x,y)};
                    pixel[0]=std::byte{255};
                    pixel[1]=std::byte{0};
                    pixel[2]=std::byte{0};
                }
            }
        }
    }
}
