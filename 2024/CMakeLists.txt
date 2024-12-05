cmake_minimum_required(VERSION 3.16)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}")

set(DAY_HEADERS
        ${SOURCE_DIR}/days/days.h
)

set(COMMON_SOURCES
        ${SOURCE_DIR}/common/competitivelib/competitive.hpp
        days/day_02.cpp
        days/day_03.cpp
        days/day_04.cpp
        days/day_05.cpp
)

add_executable(advent_of_code
        ${SOURCE_DIR}/main.cpp
        ${COMMON_SOURCES}
        days/day_01.cpp
)

target_include_directories(advent_of_code PRIVATE
        ${SOURCE_DIR}/days
        ${SOURCE_DIR}/common
)