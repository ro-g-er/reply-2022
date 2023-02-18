cmake_minimum_required(VERSION 3.23)
project(reply_2022)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(reply_2022
        src/Character.cpp
        src/Character.h)
