#pragma once
#include "Camera.h"
#include "Fragment.h"
#include "FrameBuffer.h"
#include "Object.h"
#include "Triangle.h"
#include "ZBuffer.h"
#include "../math/Matrix4f.h"

class Renderer
{
private:
    FrameBuffer& _framebuffer;
    ZBuffer& _zBuffer;
    Camera& _camera;
    Matrix4f _modelMatrix;

    inline static int frameIndex{0};//帧数
    std::vector<Object> _objects;//渲染的Obj;
    size_t width{1080};
    size_t height{720};
public:
    explicit Renderer(FrameBuffer& framebuffer,ZBuffer& zBuffer,Camera& camera ):_framebuffer(framebuffer),_zBuffer(zBuffer),_camera(camera)
    {
    };
    void setModelMatrix();
    [[nodiscard]] Matrix4f getMvp() const;

    void vertexShader();
    void fragmentShader();

    void addObject(const Object& obj);
    void draw(std::string name);
    void clear();
    ///
    ///根据现有三角形更新framebuffer
    void nextFrame();
};
