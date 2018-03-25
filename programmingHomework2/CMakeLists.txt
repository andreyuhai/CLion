cmake_minimum_required(VERSION 3.9)
project(programmingHomework2 C)

set(CMAKE_C_STANDARD 11)

add_executable(programmingHomework2 main.c odev.c odev.h)
target_link_libraries(programmingHomework2 m)