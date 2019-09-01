cmake_minimum_required(VERSION 3.14)
project(primavera_concurrente)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(primavera_concurrente main.cpp)