cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -o2)

include_directories(${CMAKE_SOURCE_DIR}/)

add_executable(localMin_test ${CMAKE_SOURCE_DIR}/tree2seq.cpp)
add_executable(printTree_test ${CMAKE_SOURCE_DIR}/printTree.cpp)

# install(TARGETS 001_test DESTINATION ${CMAKE_SOURCE_DIR}/bin/)