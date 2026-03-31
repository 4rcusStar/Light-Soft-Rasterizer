#include <fstream>
#include <iostream>

#include "../Rasterizer/FrameBuffer.h"
#include "../Rasterizer/Renderer.h"
#include "../Rasterizer/Triangle.h"
//
// Created by ASUS on 2026/3/28.
//
int main()
{
    FrameBuffer frameBuffer(256,256);
    Renderer renderer(frameBuffer);
    Triangle triangle(Vector3f(1,0,0),Vector3f(0,1,0),Vector3f(-1,0,0));
    triangle.v1.screenPosition={128,256};
    triangle.v2.screenPosition={0,0};
    triangle.v3.screenPosition={256,0};
    for (size_t x = 0; x < 256; x++)
    {
        for (size_t y = 0; y < 256; y++)
        {
            if (triangle.isInside(x,y))
            {
                std::byte* pixel = frameBuffer.pixel(x,y);
                pixel[0]=std::byte{static_cast<unsigned char>(x)};
                pixel[1]=std::byte{static_cast<unsigned char>(y)};
                pixel[2]=std::byte{0};
            }
        }
    }
    std::cout<<"success!"<<std::endl;
    renderer.draw();
}