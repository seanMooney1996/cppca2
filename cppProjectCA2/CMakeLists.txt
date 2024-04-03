cmake_minimum_required(VERSION 3.27)
project(cppProjectCA2)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppProjectCA2 main.cpp
        headers/Bug.h
        source/Bug.cpp
        source/Crawler.cpp
        headers/Crawler.h
        source/Hopper.cpp
        headers/Hopper.h
        headers/Board.h
        source/Board.cpp
        headers/Direction.h
)
