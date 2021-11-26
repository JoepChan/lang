cmake_minimum_required(VERSION 3.20)
project(lang)

set(CMAKE_CXX_STANDARD 98)

add_executable(lang main.cpp data.h decl.h defs.h scan.cpp)
