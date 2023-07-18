cmake_minimum_required(VERSION 3.10)

project(nelder_mead)

add_executable(nelder_mead
    src/main.cpp
    src/vector.hpp
    src/nelder_mead.h
    src/nelder_mead.cpp)

set_target_properties(nelder_mead PROPERTIES CXX_STANDARD 11)
