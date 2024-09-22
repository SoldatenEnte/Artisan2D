cmake_minimum_required(VERSION 3.15)
project(Artisan2D)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the source files and the resource file
add_executable(Artisan2D src/main.cpp resources.rc)
set_target_properties(Artisan2D PROPERTIES WIN32_EXECUTABLE TRUE)

# Set the path to SDL2's CMake config file directory
# Make sure this is the directory containing SDL2Config.cmake
set(SDL2_DIR "C:/Users/osteh/vcpkg/installed/x64-windows/share/sdl2")

# Find SDL2 package
find_package(SDL2 CONFIG REQUIRED)

# Include SDL2 directories
include_directories(${SDL2_INCLUDE_DIRS})

# Link SDL2 libraries
target_link_libraries(Artisan2D PRIVATE SDL2::SDL2 SDL2::SDL2main)

# Copy the correct SDL2.dll to the output directory
if (WIN32)
    add_custom_command(
        TARGET Artisan2D POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:Artisan2D>"
        VERBATIM
    )
endif()