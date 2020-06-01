# CMakeList.txt: cospath 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
project ("cospath_test")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
set(MAIN_LIB "${CMAKE_SOURCE_DIR}/os")
include_directories(${MAIN_LIB})

link_libraries("${CMAKE_SOURCE_DIR}/lib")
message(status " main lib: ${MAIN_LIB}")
# 将源代码添加到此项目的可执行文件。
add_executable (testExE "testMain.cpp" )
target_link_libraries(testExE cosp)

# TODO: 如有需要，请添加测试并安装目标。
