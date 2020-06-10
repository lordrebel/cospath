cmake_minimum_required(VERSION 3.8)

# 项目信息

project(cosp)
set(CMAKE_CXX_STANDARD 11)
#use to debug or get more data
add_definitions("-DVERBOSE_ERRORS")
if(MSVC)
#for windows set
set(BOOST_ROOT "D:\\coder\\boost\\boost_1_66_0")
find_package(BOOST  COMPONENTS filesystem)

#for windows set
message(status "lib path:${CMAKE_SOURCE_DIR}/lib")
message(Boost_INCLUDE_DIRS " ${Boost_INCLUDE_DIRS}")
message(Boost_LIBRARY_DIRS " ${Boost_LIBRARY_DIRS}")
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
endif()

set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib")

aux_source_directory(. SRC_LIST)
message(STATUS" src:${SRC_LIST}")
add_library(cosp ${SRC_LIST})
target_link_libraries(cosp boost_filesystem)
target_link_libraries(cosp boost_system)
