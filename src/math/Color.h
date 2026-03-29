#pragma once
#include <cassert>
#include <concepts>
#include "Vector3f.hpp"
template <typename T>
concept RGBValue = std::integral<T>;

struct  Color
{
public:
    int r{0}, g{0}, b{0};
    Color(RGBValue auto r, RGBValue auto g, RGBValue auto b)
        : r(static_cast<int>(r)), g(static_cast<int>(g)), b(static_cast<int>(b))
    {
        assert(r >= 0 && r <= 255 && "RGB value out of range (0-255)");
        assert(g >= 0 && g <= 255 && "RGB value out of range (0-255)");
        assert(b >= 0 && b <= 255 && "RGB value out of range (0-255)");
    }
    explicit Color(RGBValue auto rgb):Color(rgb,rgb,rgb){};
    explicit Color(Vector3f col):r(static_cast<int>(col.x)),g(static_cast<int>(col.y)),b(static_cast<int>(col.z))
    {
        assert(col.x >= 0 && col.x < 256 && "Color value out of range (0-255)");
        assert(col.y >= 0 && col.y < 256 && "Color value out of range (0-255)");
        assert(col.z >= 0 && col.z < 256 && "Color value out of range (0-255)");
    }
};
