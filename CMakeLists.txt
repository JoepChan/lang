cmake_minimum_required(VERSION 3.17)
project(lang)

set(CMAKE_CXX_STANDARD 98)

add_executable(lang main.cpp data.h decl.h defs.h scan.cpp expr.cpp interp.cpp tree.cpp expr2.cpp cg.cpp gen.cpp)
