cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -o2)

include_directories(${CMAKE_SOURCE_DIR}/)

add_executable(insertValue_test ${CMAKE_SOURCE_DIR}/insertValue.cpp)
#add_executable(remove_test ${CMAKE_SOURCE_DIR}/remove.cpp)
add_executable(divide_test ${CMAKE_SOURCE_DIR}/divide.cpp)
add_executable(commonPart_test ${CMAKE_SOURCE_DIR}/commonPart.cpp)
add_executable(inverse_test ${CMAKE_SOURCE_DIR}/inverse.cpp)
add_executable(clearValue_test ${CMAKE_SOURCE_DIR}/clearValue.cpp)
add_executable(palin_test ${CMAKE_SOURCE_DIR}/palin.cpp)


add_executable(radomList_test ${CMAKE_SOURCE_DIR}/radomList.cpp)


# install(TARGETS 001_test DESTINATION ${CMAKE_SOURCE_DIR}/bin/)