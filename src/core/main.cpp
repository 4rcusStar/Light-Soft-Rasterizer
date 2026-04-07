#include <fstream>
#include <iostream>

#include "../Rasterizer/FrameBuffer.h"
#include "../Rasterizer/Renderer.h"
// Created by ASUS on 2026/3/28.
#include "../Rasterizer/Object.h"

int main()
{
    FrameBuffer frameBuffer{1920,1080};
    ZBuffer zBuffer{1920,1080};
    Camera camera;
    camera.position={0,-.24f,.8};
    camera.fov = 3.1415926/4;
    Renderer renderer(frameBuffer,zBuffer,camera);
    Object obj;
    obj.worldPosition={0,0,0};
    std::cout<<obj.loadObj("../src/Model/marble_bust_01_1k.obj",1);
    renderer.addObject(obj);
    renderer.addLight(Light());
    renderer.nextFrame();
    std::cout<<"success!"<<std::endl;
    renderer.draw("Head_BlinnPhong.ppm");
}
