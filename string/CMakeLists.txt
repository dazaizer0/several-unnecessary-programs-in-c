cmake_minimum_required(VERSION 3.26)
project(string C)

set(CMAKE_C_STANDARD 23)

add_executable(string src/main.c
        src/lib/string.h
        src/lib/string.h)
