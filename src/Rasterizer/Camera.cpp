//
// Created by ASUS on 2026/4/5.
//

#include "Camera.h"
#include <cmath>

Camera::Camera(Vector3f position, Vector3f up,Vector3f forward, float fov, float aspectRatio, float zNear, float zFar):position(position),up(up),forward(forward),fov(fov),aspectRatio(aspectRatio),zNear(zNear),zFar(zFar)
{
}

Matrix4f Camera::getViewMatrix() const
{
    Vector3f camZ{-1*forward.normalized()};
    Vector3f camX{up.cross(camZ).normalized()};
    Vector3f camY{camZ.cross(camX)};
    Matrix4f T{1,0,0,-position.x,
               0,1,0,-position.y,
               0,0,1,-position.z,
               0,0,0,1};
    Matrix4f R{camX.x,camX.y,camX.z,0,
               camY.x,camY.y,camY.z,0,
               camZ.x,camZ.y,camZ.z,0,
                0,0,0,1};
    return R*T;
}

Matrix4f Camera::getProjectionMatrix() const
{
    const float t{std::tan(fov/2.f)};
    const float top{zNear*t};
    const float bottom{-top};
    const float right{top*aspectRatio};
    const float left{-right};
    return {
        1/(t*aspectRatio),0,0,0,
        0,1/t,0,0,
        0,0,zFar/(zFar-zNear),zNear*zFar/(zFar-zNear),
        0,0,-1,0
    };
}
