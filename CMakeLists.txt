cmake_minimum_required(VERSION 3.15)
project(Artisan2D)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/../vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Find SDL2 and ImGui packages
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(sdl2-gfx CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

# Source and header files
set(SOURCE_FILES
    src/main.cpp
    src/Core/Engine.cpp
    src/Core/Application.cpp
    src/Graphics/Renderer.cpp
    src/UI/Layout.cpp
    src/Core/Logger.cpp
    src/Blocks/KeyInputBlock.cpp
    src/Blocks/ShapeBlock.cpp
)

set(HEADER_FILES
    include/Core/Engine.h
    include/Graphics/Renderer.h
    include/UI/Layout.h
    include/Core/Application.h
    include/Colors.h
    include/Core/Logger.h
    include/Blocks/Block.h
    include/Blocks/KeyInputBlock.h
    include/Blocks/ShapeBlock.h
)

# Add executable
add_executable(Artisan2D ${SOURCE_FILES} ${HEADER_FILES} resources.rc)
set_target_properties(Artisan2D PROPERTIES WIN32_EXECUTABLE TRUE)

# Include directories
target_include_directories(Artisan2D PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link libraries (SDL2, SDL2_ttf, SDL2_gfx, ImGui)
target_link_libraries(Artisan2D
    PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_ttf::SDL2_ttf
    SDL2::SDL2_gfx
    imgui::imgui
)