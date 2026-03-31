#pragma once
#include "../math/Color.h"
#include "../math/Vector2f.h"
#include "../math/Vector3f.hpp"
#include "../math/Vector4f.h"

struct Vertex
{
    Vector3f position;
    Vector3f normal;
    Color color;
    Vector2f texCoord;

    Vector4f clipPosition{0,0,0,0};//裁剪空间坐标
    Vector3f ndcPosition{0,0,0};//ndc空间坐标
    Vector2f screenPosition{0,0};//屏幕空间坐标

    float depth{1};
    Vertex():position(0.f),normal(0.f),color(0),texCoord(0.f),depth(1.f){}
    Vertex(Vector3f pos,Vector3f col,Vector2f uv):position(pos),normal(0.f),color(col),texCoord(uv),depth(1.f){}
    Vertex(Vector3f pos,Vector3f col):Vertex(pos,col,{0,0}){};
    explicit Vertex(Vector3f pos):Vertex(pos,{255,255,255}){}
};
