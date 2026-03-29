#include <fstream>
//
// Created by ASUS on 2026/3/28.
//
int main()
{
    const int width  = 256;
    const int height = 256;

    std::ofstream ofs("output.ppm");

    // PPM 头
    ofs << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int r = x;      // 红随x渐变
            int g = 0;
            int b = y;      // 蓝随y渐变
            ofs << r << " " << g << " " << b << " ";
        }
        ofs << "\n";
    }
    return 0;
}