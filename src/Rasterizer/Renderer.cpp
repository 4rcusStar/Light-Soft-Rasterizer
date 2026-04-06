//
// Created by ASUS on 2026/3/29.
//
#include "Renderer.h"

#include <chrono>
#include <cmath>
#include <fstream>

#include "../math/MathUtils.h"
void Renderer::setModelMatrix()
{
    _modelMatrix=Matrix4f::rotateX(3.14159265358979323846/2);
}

Matrix4f Renderer::getMvp() const
{
    return _camera.getProjectionMatrix()*_camera.getViewMatrix()*_modelMatrix;
}


void Renderer::vertexShader()
{
    //渲染obj
    for (auto&obj:_objects)
    {
        for (auto&tri:obj.triangles)
        {
            for (int i{0};i<3;++i)
            {
                Vertex& v{tri[i]};
                v.clipPosition=getMvp()*Vector4f{v.position,1};
                float clipW{v.clipPosition.w};
                v.ndcPosition = {v.clipPosition.x/clipW,v.clipPosition.y/clipW,v.clipPosition.z/clipW};
                v.screenPosition = {(v.ndcPosition.x+1)*.5f*width,(v.ndcPosition.y+1)*.5f*height};
                v.depth = std::clamp((v.ndcPosition.z+1.f)*.5f,0.f,1.f);//归一化深度
            }
        }
    }
}



void Renderer::addObject(const Object &obj)
{
    _objects.push_back(obj);
}

void Renderer::draw(const std::string name)
{
    std::ofstream ofs(name,std::ios::binary);
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
    setModelMatrix();
    vertexShader();

        //遍历obj
        for (auto& obj:_objects)
        {
            //遍历obj的所有三角形
            for (auto& objTri : obj.triangles)
            {
                //获取AABB
                std::array objBoundingBox{objTri.getBoundingBox()};
                int min_y{static_cast<int>(objBoundingBox[1])};
                int min_x{static_cast<int>(objBoundingBox[0])};
                int max_x{static_cast<int>(objBoundingBox[2])};
                int max_y{static_cast<int>(objBoundingBox[3])};
                for (int y = std::max(min_y,0); y<=std::min(max_y,static_cast<int>(height-1));++y)
                {
                    for (int x = std::max(min_x,0); x<=std::min(max_x,static_cast<int>(width-1));++x)
                    {
                        if (objTri.isInside(.5f+x,y+.5f))
                        {
                            Vertex& v1 = objTri.v1;
                            Vertex& v2 = objTri.v2;
                            Vertex& v3 = objTri.v3;
                            auto [alpha,beta,gamma]= objTri.getBarycentric(x+.5f,y+.5f);
                            //重心插值
                            constexpr float eps{std::numeric_limits<float>::epsilon()};
                            float inverseDepth{alpha/std::max(v1.depth,eps)+beta/std::max(v2.depth,eps)+gamma/std::max(v3.depth,eps)};
                            float depth{1.f/std::max(inverseDepth,eps)};
                            if (depth>_zBuffer(x,y))
                                continue;
                            _zBuffer(x,y)=depth;
                            //颜色插值
                            std::byte* pixel {_framebuffer.pixel(x,y)};
                            /*Vector3f col{v1.color*alpha+v2.color*beta+v3.color*gamma};
                            pixel[0]=static_cast<std::byte>(std::round(col.x));
                            pixel[1]=static_cast<std::byte>(std::round(col.y));
                            pixel[2]=static_cast<std::byte>(std::round(col.z));*/


                            // 深度图输出（替换颜色）
                            float z = depth;
                            depth*=13;
                            depth = 1.0f - depth;

                            // 转灰度色
                            uint8_t c = static_cast<uint8_t>(depth * 255);
                            pixel[0] = static_cast<std::byte>(c);
                            pixel[1] = static_cast<std::byte>(c);
                            pixel[2] = static_cast<std::byte>(c);

                        }
                    }
                }
            }
        }
}

