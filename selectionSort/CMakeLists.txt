cmake_minimum_required(VERSION 3.9)
project(selectionSort C)

set(CMAKE_C_STANDARD 11)

add_executable(selectionSort main.c sort.c sort.h)