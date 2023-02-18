cmake_minimum_required(VERSION 3.23)
project(reply_2022)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(reply_2022
        src/Character.cpp
        src/Character.h
        src/Game.cpp
        src/Game.h)
