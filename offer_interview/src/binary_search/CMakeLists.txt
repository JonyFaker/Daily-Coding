cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -o2)

include_directories(${CMAKE_SOURCE_DIR}/)

add_executable(localMin_test ${CMAKE_SOURCE_DIR}/localMin.cpp)
add_executable(leftMost_test ${CMAKE_SOURCE_DIR}/leftMost.cpp)
add_executable(getMinCycle_test ${CMAKE_SOURCE_DIR}/getMinCycle.cpp)
add_executable(findLeftMost_test ${CMAKE_SOURCE_DIR}/findLeftMost.cpp)
add_executable(countNode_test ${CMAKE_SOURCE_DIR}/countNode.cpp)
add_executable(quickPower_test ${CMAKE_SOURCE_DIR}/quickPower.cpp)

# install(TARGETS 001_test DESTINATION ${CMAKE_SOURCE_DIR}/bin/)