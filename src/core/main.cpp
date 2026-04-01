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
    FrameBuffer frameBuffer(1080,720);
    Renderer renderer(frameBuffer);
    Triangle triangle(Vector3f(1,0,0),Vector3f(0,1,0),Vector3f(-1,0,0));
    Triangle triangle2(triangle);
    triangle.v1.screenPosition={0,0};
    triangle.v2.screenPosition={0,10};
    triangle.v3.screenPosition={10,0};
    triangle.v1.depth=1.0f;
    triangle.v2.depth=1.0f;
    triangle.v3.depth=1.0f;
    triangle2.v1.screenPosition={0,0};
    triangle2.v2.screenPosition={44,55};
    triangle2.v3.screenPosition={201,77};
    triangle2.v1.depth=.5f;
    triangle2.v2.depth=.5f;
    triangle2.v3.depth=.5f;
    renderer.addTriangle(triangle);
    renderer.addTriangle(triangle2);
    renderer.nextFrame();
    std::cout<<"success!"<<std::endl;
    renderer.draw();
}