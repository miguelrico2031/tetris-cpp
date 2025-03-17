cmake_minimum_required(VERSION 3.28)
project(tetris-cpp LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(tetris-cpp 
    src/main.cpp
    src/const.h
)



target_compile_features(tetris-cpp PRIVATE cxx_std_17)
target_link_libraries(tetris-cpp PRIVATE SFML::Graphics)
