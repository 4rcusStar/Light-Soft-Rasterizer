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
    FrameBuffer frameBuffer{1080,720};
    ZBuffer zBuffer{1080,720};
    Camera camera;
    camera.position={0,0,4};
    Renderer renderer(frameBuffer,zBuffer,camera);

    // 白色三角形
    Triangle whiteTri;
    whiteTri.v1.position = { -1.0f,  0.8f, -1.2f }; // 上左：极近
    whiteTri.v2.position = {  10.0f,  0.8f, -2.8f }; // 上右：极远
    whiteTri.v3.position = {  0.0f, -0.8f, -2.0f }; // 下中：中间
    whiteTri.v1.color = {255,255,255};
    whiteTri.v2.color = {255,255,255};
    whiteTri.v3.color = {255,255,255};
    renderer.addTriangle(whiteTri);

    // 彩色三角形
    Triangle colorTri;
    colorTri.v1.position = { -10.0f,  0.8f, -2.8f }; // 上左：极远
    colorTri.v2.position = {  1.0f,  0.8f, -1.2f }; // 上右：极近
    colorTri.v3.position = {  0.0f, -0.8f, -2.0f }; // 下中：中间
    colorTri.v1.color = {255, 0, 0};
    colorTri.v2.color = {0, 255, 0};
    colorTri.v3.color = {0, 0, 255};
    renderer.addTriangle(colorTri);
    renderer.nextFrame();
    std::cout<<"success!"<<std::endl;
    renderer.draw();
}