cmake_minimum_required(VERSION 3.9)
project(problem3 C)

set(CMAKE_C_STANDARD 11)

add_executable(problem3 main.c)
target_link_libraries(problem3 m)