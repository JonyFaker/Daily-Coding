cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -o2)

include_directories(${CMAKE_SOURCE_DIR}/)

add_executable(getminStack_test ${CMAKE_SOURCE_DIR}/getminStack.cpp)
add_executable(twoStack_test ${CMAKE_SOURCE_DIR}/twoStack.cpp)
add_executable(stackReverse_test ${CMAKE_SOURCE_DIR}/stackReverse.cpp)
add_executable(stackSort_test ${CMAKE_SOURCE_DIR}/stackSort.cpp)

add_executable(window_test ${CMAKE_SOURCE_DIR}/window.cpp)
add_executable(maxTree_test ${CMAKE_SOURCE_DIR}/maxTree.cpp)


# install(TARGETS 001_test DESTINATION ${CMAKE_SOURCE_DIR}/bin/)