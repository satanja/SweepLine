cmake_minimum_required(VERSION 3.10)
project(sweepline)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/main.cpp
)

add_executable(sweepline ${SOURCES})