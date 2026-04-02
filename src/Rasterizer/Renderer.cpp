//
// Created by ASUS on 2026/3/29.
//
#include "Renderer.h"

#include <chrono>
#include <cmath>
#include <fstream>

#include "../math/MathUtils.h"
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
    //清除缓存数据
    _zBuffer.clear();
    _framebuffer.clear();
    //外层遍历三角形
    for (auto& tri : _triangles)
    {
        //获取AABB
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
                    Vertex& v1 = tri.v1;
                    Vertex& v2 = tri.v2;
                    Vertex& v3 = tri.v3;
                    auto [alpha,beta,gamma]= tri.getBarycentric(x+.5f,y+.5f);
                    //重心插值
                    constexpr float eps{std::numeric_limits<float>::epsilon()};
                    float inverseDepth{alpha/std::max(v1.depth,eps)+beta/std::max(v2.depth,eps)+gamma/std::max(v3.depth,eps)};
                    float depth{1.f/std::max(inverseDepth,eps)};
                    if (depth>_zBuffer(x,y))
                        continue;
                    _zBuffer(x,y)=depth;
                    //颜色插值
                    std::byte* pixel {_framebuffer.pixel(x,y)};
                    Vector3f col{v1.color*alpha+v2.color*beta+v3.color*gamma};
                    pixel[0]=static_cast<std::byte>(std::round(col.x));
                    pixel[1]=static_cast<std::byte>(std::round(col.y));
                    pixel[2]=static_cast<std::byte>(std::round(col.z));
                }
            }
        }
    }
}

