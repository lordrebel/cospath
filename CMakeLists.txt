# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("cospath")

# 包含子项目。
add_subdirectory("os")
add_subdirectory ("test")
#add_dependencies("test" "os")


