cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -o2)

include_directories(${CMAKE_SOURCE_DIR}/)

# add_executable(identicalTree_test ${CMAKE_SOURCE_DIR}/identicalTree.cpp)
add_executable(TransForm_test ${CMAKE_SOURCE_DIR}/TransForm.cpp)
add_executable(rotationString_test ${CMAKE_SOURCE_DIR}/rotationString.cpp)
add_executable(reverseStr_test ${CMAKE_SOURCE_DIR}/reverseStr.cpp)
add_executable(translation_test ${CMAKE_SOURCE_DIR}/translation.cpp)
add_executable(Prior_test ${CMAKE_SOURCE_DIR}/Prior.cpp)

add_executable(replaceBlank_test ${CMAKE_SOURCE_DIR}/replaceBlank.cpp)
add_executable(parenthesis_test ${CMAKE_SOURCE_DIR}/parenthesis.cpp)
add_executable(nonRepeatSubstr_test ${CMAKE_SOURCE_DIR}/nonRepeatSubstr.cpp)

# install(TARGETS 001_test DESTINATION ${CMAKE_SOURCE_DIR}/bin/)