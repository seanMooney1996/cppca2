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
        source/Splitter.cpp
        headers/Splitter.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(cppProjectCA2 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)