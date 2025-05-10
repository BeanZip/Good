cmake_minimum_required(VERSION 4.0.0)
project(Good C)


file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(Good ${SOURCES})

target_include_directories(Good PRIVATE include)
