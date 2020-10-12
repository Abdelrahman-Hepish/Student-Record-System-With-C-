cmake_minimum_required(VERSION 3.17)
project(intermdiate_lvl_project C)

set(CMAKE_C_STANDARD 90)

add_executable(intermdiate_lvl_project main.c system.c system.h interfacing.h interfacing.c database.c database.h)