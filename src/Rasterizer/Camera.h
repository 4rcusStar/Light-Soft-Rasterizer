//
// Created by ASUS on 2026/4/5.
//

#ifndef SOFTRASTERIZER_CAMERA_H
#define SOFTRASTERIZER_CAMERA_H
#include "../math/Matrix4f.h"
#include "../math/Vector3f.hpp"


class Camera
{
public:
    Vector3f position;
    Vector3f up;
    Vector3f forward;
    float fov;
    float aspectRatio;
    float zNear;
    float zFar;

    Camera(Vector3f position={0,0,0},Vector3f up={0,1,0},Vector3f lookAt={0,0,-1},float fov=90, float aspectRatio=16.f/9, float zNear=.1f, float zFar=100);
    [[nodiscard]]Vector3f getLookAt() const {return position+forward;}
    [[nodiscard]] Matrix4f getViewMatrix() const;
    [[nodiscard]] Matrix4f getProjectionMatrix() const;
};


#endif //SOFTRASTERIZER_CAMERA_H