cmake_minimum_required(VERSION 3.21)
project(bruteslide C)

set(CMAKE_C_STANDARD 23)

add_executable(bruteslide main.c bruteslide.c types.h trig_table.c maths.c maths.h bruteslide.h surface.h surface.c)
