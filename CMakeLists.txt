cmake_minimum_required(VERSION 3.5)

project(GraphicsMap)

add_subdirectory(GraphicsMapLib)
add_subdirectory(GraphicsMapApp)

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})
