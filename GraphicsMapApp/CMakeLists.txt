cmake_minimum_required(VERSION 3.5)

project(GraphicsMapApp LANGUAGES CXX)
set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(${PROJECT_NAME}
    main.cpp
)

#
target_link_libraries(${PROJECT_NAME} PRIVATE Lib::GraphicsMap)

#
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION install)
