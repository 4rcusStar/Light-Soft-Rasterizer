//
// Created by ASUS on 2026/4/6.
//

#ifndef SOFTRASTERIZER_OBJECT_H
#define SOFTRASTERIZER_OBJECT_H
#include <vector>
#include <fstream>
#include <sstream>
#include "Triangle.h"


class Object
{
public:
    Vector3f worldPosition{0,0,0};
    std::vector<Triangle> triangles;
    std::vector<Vector3f> vertexPositions;
    std::vector<Vector3f> normals;
    std::vector<Vector2f> uvs;
    /// 解析obj文件
    /// @param path 文件路径
    /// @return 是否解析成功
    bool loadObj(const std::string& path);

    bool loadObj(const std::string &path, float scale);
};


#endif //SOFTRASTERIZER_OBJECT_H