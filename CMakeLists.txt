cmake_minimum_required(VERSION 3.16)

project(GameEngine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_library(GLAD
    External/GLAD/src/glad.c
)

target_include_directories(GLAD PUBLIC
    External/GLAD/include
)

add_subdirectory(External/SDL)
add_subdirectory(Engine)
add_subdirectory(Sandbox)