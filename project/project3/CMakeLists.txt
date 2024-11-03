cmake_minimum_required(VERSION 3.12)

#add_definitions(-DWITH_NEON)
add_definitions(-DWITH_AVX2)
add_definitions(-mavx)
add_definitions(-O3)

set(CMAKE_CXX_STANDARD 11)

project(dotp)

ADD_EXECUTABLE(dotp convolution.c )

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message("OpenMP found.")
    target_link_libraries(dotp PUBLIC OpenMP::OpenMP_CXX)
endif()
