cmake_minimum_required(VERSION 3.16)
project(22s_pa01_cout_this_one_hazel_endl)

set(CMAKE_CXX_STANDARD 14)
# Copy data files to build dir
set(input01 "input/test.txt")
foreach(file IN LISTS input01)
    configure_file(${file} ${file} COPYONLY)
endforeach()
include_directories(.)

add_executable(22s_pa01_cout_this_one_hazel_endl
        src/main.cpp src/Painting.cpp src/Painting.h
        src/Algorithm.cpp src/Algorithm.h src/Subset.cpp src/Subset.h)
