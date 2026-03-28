cmake_minimum_required(VERSION 3.10)
project(SoftRasterizer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(SoftRasterizer ${SOURCES}
        src/math/main.cpp
        src/math/Vector4f.cpp
        src/math/Vector4f.h
        src/math/Matrix4f.cpp
        src/math/Matrix4f.h)

if(MSVC)
    target_compile_options(SoftRasterizer PRIVATE /W4)
else()
    target_compile_options(SoftRasterizer PRIVATE -Wall -Wextra -Wpedantic)
endif()
