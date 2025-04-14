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
    src/GameplayScene.cpp
    src/Board.cpp
    src/MovingPiece.cpp
    src/Piece.cpp    
    src/MovingPieceState.cpp 
    src/GameplayState.cpp 
    src/ClearRowsState.cpp
    src/Level.cpp 
    src/Generator.cpp
    src/HoldPanel.cpp
    src/ScorePanel.cpp
    src/NextPiecePanel.cpp
    src/MenuScene.cpp
    src/GameOverScene.cpp
    src/Button.cpp
    src/ButtonManager.cpp
    src/Save.cpp
)


target_compile_features(tetris-cpp PRIVATE cxx_std_17)
target_link_libraries(tetris-cpp PRIVATE SFML::Graphics)

set(RESOURCE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/resources")
set(RESOURCE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/resources")

file(GLOB_RECURSE RESOURCE_FILES "${RESOURCE_SOURCE_DIR}/*")


# Crear el directorio si no existe
file(MAKE_DIRECTORY "${RESOURCE_OUTPUT_DIR}")

# Añadir comando para copiar cada archivo
foreach(RESOURCE_FILE ${RESOURCE_FILES})
    get_filename_component(FILENAME ${RESOURCE_FILE} NAME)
    add_custom_command(
        OUTPUT "${RESOURCE_OUTPUT_DIR}/${FILENAME}"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${RESOURCE_FILE}"
                "${RESOURCE_OUTPUT_DIR}/${FILENAME}"
        DEPENDS "${RESOURCE_FILE}"
    )
    list(APPEND COPIED_RESOURCES "${RESOURCE_OUTPUT_DIR}/${FILENAME}")
endforeach()

# Crear un target personalizado que agrupe todos los archivos copiados
add_custom_target(copy_resources ALL DEPENDS ${COPIED_RESOURCES})

# Asegurar que se copien después de compilar tu ejecutable
add_dependencies(tetris-cpp copy_resources)

