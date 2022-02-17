cmake_minimum_required(VERSION 3.21)
project(bruteslide C)

set(CMAKE_C_STANDARD 23)

add_executable(bruteslide main.c types.h bruteslide.c trig_table.c)
