cmake_minimum_required(VERSION 3.16)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp main.cpp Array.h smartpointer.h Exception.cpp Exception.h Object.h Object.cpp)