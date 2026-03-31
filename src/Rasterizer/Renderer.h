#pragma once
#include "FrameBuffer.h"
class Renderer
{
    //TODO:`完成Renderer的完全构造函数
    //     `完成draw，clear函数，其中draw接受framebuffer&作为参数
private:
    FrameBuffer& _framebuffer;
public:
    explicit Renderer(FrameBuffer& framebuffer):_framebuffer(framebuffer){};
    void draw();
    void clear();
};
