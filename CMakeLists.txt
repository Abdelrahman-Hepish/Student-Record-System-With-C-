cmake_minimum_required(VERSION 3.17)
project(App_list C)

set(CMAKE_C_STANDARD 99)

add_executable(App_list main.c system.c system.h admin.c admin.h List.h List.c database.h database.c interfacing.c interfacing.h student.h student.c)