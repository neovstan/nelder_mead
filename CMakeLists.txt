cmake_minimum_required(VERSION 3.10)

project(nelder_mead)

add_executable(nelder_mead
    src/main.cpp
    src/nelder_mead.cpp
    include/nelder_mead/nelder_mead.h
    include/nelder_mead/vector.hpp)

target_include_directories(nelder_mead PRIVATE include/nelder_mead)
target_include_directories(nelder_mead PUBLIC include)

set_target_properties(nelder_mead PROPERTIES CXX_STANDARD 11)
