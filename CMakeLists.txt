cmake_minimum_required(VERSION 3.13)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 14)
include_directories(inc)

add_executable(DesignPatterns main.cpp src/pimpl.cpp)
