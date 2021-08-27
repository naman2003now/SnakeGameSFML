cmake_minimum_required(VERSION 3.1)
project(SnakeGame)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_executable(${PROJECT_NAME} src/main.cpp src/Snake.cpp)
link_directories(lib)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} sfml-window sfml-system sfml-graphics)