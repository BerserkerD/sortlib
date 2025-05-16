cmake_minimum_required(VERSION 3.10)

project(sortlib C CXX)

# 设置 C 和 C++ 标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# 包含头文件目录
include_directories(include)

# 排序算法源文件（C）
set(SORT_SOURCES
    src/sort.c
)

# 创建静态库 sortlib
add_library(sortlib STATIC ${SORT_SOURCES})

# 添加测试程序
add_executable(test test/test.cpp)

# 链接排序库到测试程序
target_link_libraries(test sortlib)
