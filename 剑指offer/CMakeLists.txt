cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -o2)

include_directories(${CMAKE_SOURCE_DIR}/)


add_executable(001_test ${CMAKE_SOURCE_DIR}/001.cpp)
add_executable(002_test ${CMAKE_SOURCE_DIR}/002.cpp)

# install(TARGETS 001_test DESTINATION ${CMAKE_SOURCE_DIR}/bin/)