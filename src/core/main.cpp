#include <fstream>
#include <iostream>

#include "../Rasterizer/FrameBuffer.h"
#include "../Rasterizer/Renderer.h"
#include "../Rasterizer/Triangle.h"
//
// Created by ASUS on 2026/3/28.
#include "../math/MathUtils.h"
int main()
{
    constexpr  size_t WIDTH {256};
    constexpr  size_t HEIGHT {256};
    FrameBuffer frameBuffer(WIDTH,HEIGHT);
    ZBuffer zBuffer(WIDTH,HEIGHT);
    Renderer renderer(frameBuffer,zBuffer);

    /*Triangle triangle(Vector3f(1,0,0),Vector3f(0,1,0),Vector3f(-1,0,0));
    triangle.v1.screenPosition ={0,256};
    triangle.v2.screenPosition ={128,0};
    triangle.v3.screenPosition ={256,256};
    triangle.v1.color={0,255,0};
    triangle.v2.color={0,255,0};
    triangle.v3.color={0,255,0};
    triangle.v1.depth=.2f;
    triangle.v2.depth=.3f;
    triangle.v3.depth=.3F;*/

    Triangle triangle2(Vector3f(1,0,0),Vector3f(0,1,0),Vector3f(-1,0,0));
    triangle2.v1.screenPosition ={0,256};
    triangle2.v2.screenPosition ={128,0};
    triangle2.v3.screenPosition ={256,256};
    triangle2.v1.color=triangle2.v2.color=triangle2.v3.color={255,255,255};
    triangle2.v1.depth =.02;
    triangle2.v2.depth =.5F;
    triangle2.v3.depth =.1F;
    //renderer.addTriangle(triangle);
    renderer.addTriangle(triangle2);
    renderer.nextFrame();
    std::cout<<"success!"<<std::endl;
    renderer.draw();
}