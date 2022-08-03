# Copyright (c) Brandon Pacewic
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23.2)

project(monty_hall_sim LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
set_target_properties(src PROPERTIES LINKER_LANGUAGE CXX)

add_executable(monty_hall_sim src/main.cpp)
target_link_libraries(monty_hall_sim PUBLIC src)

target_include_directories(monty_hall_sim PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/src")