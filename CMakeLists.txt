cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp)

target_include_directories(untitled PUBLIC /usr/include/SFML)
target_link_libraries(untitled sfml-system sfml-window sfml-graphics)
