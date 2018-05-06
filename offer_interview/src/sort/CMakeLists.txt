cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -o2)

include_directories(${CMAKE_SOURCE_DIR}/)

###  sort
add_executable(bubbleSort_test ${CMAKE_SOURCE_DIR}/bubbleSort.cpp)
add_executable(chooseSort_test ${CMAKE_SOURCE_DIR}/chooseSort.cpp)
add_executable(insertSort_test ${CMAKE_SOURCE_DIR}/insertSort.cpp)
add_executable(mergeSort_test ${CMAKE_SOURCE_DIR}/mergeSort.cpp)
add_executable(quickSort_test ${CMAKE_SOURCE_DIR}/quickSort.cpp)

# install(TARGETS 001_test DESTINATION ${CMAKE_SOURCE_DIR}/bin/)