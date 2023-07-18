cmake_minimum_required(VERSION 3.10)

project(nelder_mead)

add_executable(nelder_mead
    main.cpp
    vector.hpp
    nelder_mead.h
    nelder_mead.cpp)

set_target_properties(nelder_mead PROPERTIES CXX_STANDARD 11)
