# Copyright (c) Brandon Pacewic
# SPDX-License-Identifier: MIT

set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/monty_hall.hpp
)

add_library(src ${SOURCES})

target_include_directories(src PUBLIC ${CMAKE_CURRENT_LIST_DIR})