#pragma once
#include "FrameBuffer.h"
#include "Triangle.h"
#include "ZBuffer.h"
#include "../math/Matrix4f.h"

class Renderer
{
private:
    FrameBuffer& _framebuffer;
    ZBuffer& _zBuffer;
    Matrix4f _modelMatrix;
    Matrix4f _viewMatrix;
    Matrix4f _projectionMatrix;

    std::vector<Triangle> _triangles;
public:
    explicit Renderer(FrameBuffer& framebuffer,ZBuffer& zBuffer):_framebuffer(framebuffer),_zBuffer(zBuffer){};
    void setModelMatrix(Matrix4f m);
    void setViewMatrix(Matrix4f v);
    void setProjectionMatrix(Matrix4f p);

    void addTriangle(const Triangle& tri);
    void draw();
    void clear();
    ///
    ///根据现有三角形更新framebuffer
    void nextFrame();
};
