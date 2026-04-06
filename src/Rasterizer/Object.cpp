//
// Created by ASUS on 2026/4/6.
//

#include "Object.h"

#include <cstring>
#include <ranges>

/// 根据特定字符分割字符串
/// @param str 源字符串
/// @param delimiter 标志
/// @return
inline std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != std::string::npos)
    {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }

    result.push_back(str.substr(start));
    return result;
}
bool Object::loadObj(const std::string &path)
{
    return loadObj(path,1);
}
bool Object::loadObj(const std::string &path,const float scale)
{
    std::cout<<"loading obj "<<path<<std::endl;
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cout<<"Error loading obj: "<<strerror(errno)<<path<<std::endl;
        return false;
    };
    std::string line;
    while (std::getline(file,line))
    {
        if (line.empty()||line[0] == '#') continue;
        std::istringstream stringStream(line);
        std::string dataType;
        stringStream >> dataType;
        //读取顶点
        if (dataType == "v")
        {
            Vector3f v{0,0,0};
            stringStream >> v.x >> v.y >> v.z;
            v*=scale;
            v+=worldPosition;
            vertexPositions.push_back(v);
        }
        else if (dataType == "vn")
        {
            Vector3f vn{0,0,0};
            stringStream >> vn.x >> vn.y >> vn.z;
            normals.push_back(vn);
        }
        else if (dataType == "vt")
        {
            Vector2f vt{0,0};
            stringStream >> vt.x >> vt.y;
            uvs.push_back(vt);
        }
        else if (dataType == "f")
        {
            Triangle tri;
            for (int i = 0; i < 3; ++i)
            {
                std::string vGroup;
                stringStream >> vGroup;
                auto parts = split(vGroup,"/");
                std::array<int,3> partsInt{std::stoi(parts[0]),std::stoi(parts[1]),std::stoi(parts[2])};
                Vertex vertex;
                vertex.position = vertexPositions.at(partsInt[0]-1);
                vertex.texCoord = uvs.at(partsInt[1]-1);
                vertex.normal = normals.at(partsInt[2]-1);
                tri[i]=vertex;
            }
            triangles.push_back(tri);
        }
    }
    return true;
}

