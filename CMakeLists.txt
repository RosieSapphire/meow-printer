cmake_minimum_required(VERSION 3.22.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(meow-printer)

add_executable(meow-printer src/vec2.h src/term.h src/term.cpp src/meow.h src/meow.cpp src/main.cpp)
