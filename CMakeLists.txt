cmake_minimum_required(VERSION 3.21)
project(bruteslide C)

set(CMAKE_C_STANDARD 23)

add_executable(bruteslide main.c settings.h types.h bruteslide.c trig_table.inc.c)
