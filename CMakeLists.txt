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
    src/Game.cpp
    src/Logger.cpp
    src/MovingPiece.cpp
    src/GameplayScene.cpp
    src/Board.cpp
    src/Piece.h 
    src/Rotations.h
    src/Colors.h
    src/Piece.cpp
)



target_compile_features(tetris-cpp PRIVATE cxx_std_17)
target_link_libraries(tetris-cpp PRIVATE SFML::Graphics)


# Define la ruta de las texturas
set(TEXTURE_DIR "${CMAKE_BINARY_DIR}/textures")

# Asegurar que la carpeta de salida existe
file(MAKE_DIRECTORY ${TEXTURE_DIR})

# Copiar la textura al directorio de salida cada vez que se compila
add_custom_command(TARGET tetris-cpp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    "${CMAKE_SOURCE_DIR}/textures/tex.png"
    "${TEXTURE_DIR}/tex.png"
)
