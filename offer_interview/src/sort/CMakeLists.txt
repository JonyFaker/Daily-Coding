cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)
add_definitions(-g -o2)

include_directories(${CMAKE_SOURCE_DIR}/)

###  sort
#### O(N2)
add_executable(bubbleSort_test ${CMAKE_SOURCE_DIR}/O_N2/bubbleSort.cpp)
add_executable(chooseSort_test ${CMAKE_SOURCE_DIR}/O_N2/chooseSort.cpp)
add_executable(insertSort_test ${CMAKE_SOURCE_DIR}/O_N2/insertSort.cpp)

#### O(NlogN)
add_executable(mergeSort_test ${CMAKE_SOURCE_DIR}/O_NlogN/mergeSort.cpp)
add_executable(quickSort_test ${CMAKE_SOURCE_DIR}/O_NlogN/quickSort.cpp)
add_executable(heapSort_test ${CMAKE_SOURCE_DIR}/O_NlogN/heapSort.cpp)
add_executable(shellSort_test ${CMAKE_SOURCE_DIR}/O_NlogN/shellSort.cpp)

#### O(N)
add_executable(countingSort_test ${CMAKE_SOURCE_DIR}/O_N/countingSort.cpp)
add_executable(radixSort_test ${CMAKE_SOURCE_DIR}/O_N/radixSort.cpp)

# install(TARGETS 001_test DESTINATION ${CMAKE_SOURCE_DIR}/bin/)