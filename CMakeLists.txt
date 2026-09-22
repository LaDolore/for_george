cmake_minimum_required(VERSION 4.3)
project(for_george)

set(CMAKE_CXX_STANDARD 20)

add_executable(for_george main.cpp
        CustomDynamicArray.cpp
        CustomDynamicArray.h)
