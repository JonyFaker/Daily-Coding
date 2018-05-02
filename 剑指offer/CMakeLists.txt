cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -o2)

include_directories(${CMAKE_SOURCE_DIR}/)


add_executable(001_test ${CMAKE_SOURCE_DIR}/src/001.cpp)
add_executable(002_test ${CMAKE_SOURCE_DIR}/src/002.cpp)
add_executable(003_test ${CMAKE_SOURCE_DIR}/src/003.cpp)
add_executable(004_test ${CMAKE_SOURCE_DIR}/src/004.cpp)
add_executable(005_test ${CMAKE_SOURCE_DIR}/src/005.cpp)
# add_executable(006_test ${CMAKE_SOURCE_DIR}/src/006.cpp)
add_executable(007_test ${CMAKE_SOURCE_DIR}/src/007.cpp)

# install(TARGETS 001_test DESTINATION ${CMAKE_SOURCE_DIR}/bin/)