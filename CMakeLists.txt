cmake_minimum_required(VERSION 3.15)
project(Artisan2D)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set the vcpkg toolchain file path
set(CMAKE_TOOLCHAIN_FILE "C:/Users/osteh/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Find SDL2 packages
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(sdl2-gfx CONFIG REQUIRED)


# Add the source files and the resource file
add_executable(Artisan2D
    src/main.cpp
    resources.rc
    "src/Core/Engine.cpp"
    "src/Core/Application.cpp"
    "src/Graphics/Renderer.cpp"
    "src/UI/Layout.cpp"
    "include/Core/Engine.h"
    "include/Graphics/Renderer.h"
    "include/UI/Layout.h"
    "include/Core/Application.h"
    "include/Colors.h"
 "include/Core/Logger.h" "src/Core/Logger.cpp")

set_target_properties(Artisan2D PROPERTIES WIN32_EXECUTABLE TRUE)

# Include directories
target_include_directories(Artisan2D PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link libraries
target_link_libraries(Artisan2D
    PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_ttf::SDL2_ttf
    SDL2::SDL2_gfx
)