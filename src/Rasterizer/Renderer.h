#pragma once
#include "Camera.h"
#include "Fragment.h"
#include "FrameBuffer.h"
#include "Light.h"
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
    size_t width{1920};
    size_t height{1080};
    static constexpr float ambientCoefficient{.01f};
    static constexpr float specularCoefficient{5.f};
    static constexpr float p{50.f};
    static constexpr float diffuseCoefficient{5.f};
    std::vector<Light> _lights;
public:
    explicit Renderer(FrameBuffer& framebuffer,ZBuffer& zBuffer,Camera& camera ):_framebuffer(framebuffer),_zBuffer(zBuffer),_camera(camera)
    {
    };
    void setModelMatrix();
    [[nodiscard]] Matrix4f getMvp() const;

    void vertexShading();
    void fragmentShading();


    void addObject(const Object& obj);
    void addLight(const Light& light);
    void draw(const std::string &name);
    void clear();
    ///
    ///根据现有三角形更新framebuffer
    void nextFrame();
};
