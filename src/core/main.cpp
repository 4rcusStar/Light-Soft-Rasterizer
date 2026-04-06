#include <fstream>
#include <iostream>

#include "../Rasterizer/FrameBuffer.h"
#include "../Rasterizer/Renderer.h"
// Created by ASUS on 2026/3/28.
#include "../Rasterizer/Object.h"

int main()
{
    FrameBuffer frameBuffer{1080,720};
    ZBuffer zBuffer{1080,720};
    Camera camera;
    camera.position={0,-.2,.8};
    camera.fov = 3.1415926/4;
    Renderer renderer(frameBuffer,zBuffer,camera);
    Object obj;
    obj.worldPosition={0,0,0};
    std::cout<<obj.loadObj("../src/Model/marble_bust_01_1k.obj",1);
    renderer.addObject(obj);
    renderer.nextFrame();
    std::cout<<"success!"<<std::endl;
    renderer.draw("DepthImage.ppm");
}
