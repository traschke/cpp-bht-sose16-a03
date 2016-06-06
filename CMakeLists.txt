cmake_minimum_required(VERSION 3.5)
project(cpp_bht_sose16_a03)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test_my_vector.cpp my_vector.h ring_array.cpp ring_array.h test_ring_array.cpp)
add_executable(cpp_bht_sose16_a03 ${SOURCE_FILES})