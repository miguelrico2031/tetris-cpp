# Tetris Clone in C++

A Tetris clone developed in C++ using SFML to enhance my C++ programming skills. The game includes the original Tetris's core features and some additional ones.

## Features

- **Dynamic Difficulty**: The game increases in difficulty as you progress.
- **Hold Piece**: Save a piece for later use.
- **Next Pieces Preview**: View the next three pieces to plan your moves.
- **Level Selection**: Choose your starting level from the main menu.
- **High Score Tracking**: Keep track of your best scores.

## Compilation Instructions

### Recommended: Using Visual Studio 2022 (Windows)

1. Ensure you have Visual Studio 2022 installed with the "Desktop development with C++" workload.
2. Clone the repository:

      `git clone https://github.com/miguelrico2031/tetris-cpp.git`

      `cd tetris-cpp`
3. Open the project in Visual Studio using "Open a Local Folder" option.
4. Build the project by selecting the desired configuration (e.g., Debug or Release) and clicking "Build" > "Build All" from the menu.

### Alternative: Using CMake and Ninja

1. Ensure you have the following installed:
   - [CMake](https://cmake.org/download/) (version 3.15 or higher)
   - [Ninja](https://ninja-build.org/)
   - A C++17 compatible compiler
   - [SFML](https://www.sfml-dev.org/) dependencies (refer to your system's package manager or SFML documentation)

2. Clone the repository:

      `git clone https://github.com/miguelrico2031/tetris-cpp.git`

      `cd tetris-cpp`
   
3. Create a build directory and configure the project:
      
      `cmake -B build -G Ninja`
   
4. Build the project:
      
      `cmake --build build`
   
## Execution Instructions

After building, navigate to the directory containing the executable and run it.
   
## Controls

- **Move Left**: `A` or `Left Arrow`
- **Move Right**: `D` or `Right Arrow`
- **Rotate Clockwise**: `W` or `Up Arrow`
- **Rotate Counter-Clockwise**: `Z`
- **Faster Drop**: `S` or `Down Arrow`
- **Hold Piece**: `C`