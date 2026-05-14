cmake_minimum_required(VERSION 3.22)
project(first_project)

set(CMAKE_CXX_STANDARD 17) # -std=c++17

set(CMAKE_EXPORT_COMPILE_COMMANDS_ON)

add_library(tools tools.cpp)
add_executable(main main.cpp)
target_link_libraries(main tools)
