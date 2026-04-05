//
// Created by ASUS on 2026/3/29.
//

#ifndef SOFTRASTERIZER_FRAMEBUFFER_H
#define SOFTRASTERIZER_FRAMEBUFFER_H
#include <vector>
class FrameBuffer
{
private:
    size_t _width{0};
    size_t _height{0};
    std::vector<std::byte> _data;
    const size_t bytesPerPixel{4};
public:
    /// 所有pixel byte初始化为0
    /// @param width
    /// @param height
    FrameBuffer(size_t width, size_t height):_width(width),_height(height)
    {
        _data.resize(width*height*bytesPerPixel);
        std::fill(_data.begin(),_data.end(),std::byte{0});
    }
    ///
    /// @param x
    /// @param y
    /// @return 在(x，y)处的像素指针(使用)
    [[nodiscard]]std::byte* pixel(size_t x,size_t y)
    {
        return _data.data()+(y*_width+x)*bytesPerPixel;
    }
    ///
    /// @param x
    /// @param y
    /// @return 在(x，y)处的像素指针(使用)
    [[nodiscard]] const std::byte* pixel(size_t x,size_t y)const{return _data.data()+(y*_width+x)*bytesPerPixel;}
    void clear()
    {
        std::fill(_data.begin(),_data.end(),std::byte{0});
    }
    [[nodiscard]] size_t getWidth()const{return _width;}
    [[nodiscard]] size_t getHeight()const{return _height;}
};


#endif //SOFTRASTERIZER_FRAMEBUFFER_H