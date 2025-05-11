cmake_minimum_required(VERSION 3.15)
project(Good C)


file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(Good ${SOURCES})

target_include_directories(Good PRIVATE include)
