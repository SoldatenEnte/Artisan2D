# Artisan2D

Artisan2D is a game engine designed to empower your creativity in crafting captivating 2D experiences. Built exclusively for 2D game development, Artisan2D combines simplicity with power, offering a modern modular UI that streamlines your workflow.

## Features

- **Modular Building Blocks**: Create your game using customizable blocks without writing code.
- **User-Friendly Interface**: Intuitive design that caters to both beginners and experienced developers.
- **Cross-Platform Support**: Build and run your games on multiple platforms.

## Getting Started

### Prerequisites

Before you begin, ensure you have the following installed on your system:

- **CMake**: [Download and install CMake](https://cmake.org/download/)
- **Visual Studio**: [Download Visual Studio](https://visualstudio.microsoft.com/) (ensure you have the Desktop development with C++ workload)
- **vcpkg** (for package management):
  - Clone the repository:
    ```bash
    git clone https://github.com/microsoft/vcpkg.git
    ```
  - Navigate to the vcpkg directory:
    ```bash
    cd vcpkg
    ```
  - Run the bootstrap script:
    ```bash
    .\bootstrap-vcpkg.bat
    ```

### Installing SDL2

To install SDL2 and its dependencies, use the following commands:

```bash
vcpkg install sdl2 sdl2-image
vcpkg integrate install
```

### Cloning the Repository

Clone the Artisan2D repository to your local machine:

```bash
git clone https://github.com/soldatenente/Artisan2D.git
cd Artisan2D
```

### Configuring the Project

1. **Modify CMakeLists.txt**: Open the `CMakeLists.txt` file in the Artisan2D directory. Update the SDL2 directory path to match your vcpkg installation:

   ```cmake
   set(SDL2_DIR "C:/path/to/vcpkg/installed/x64-windows/share/sdl2")
   ```

   Replace `C:/path/to/vcpkg` with the actual path to your vcpkg installation.

2. **Build the Project**: Open the solution in Visual Studio and build it directly. The build process will configure the project automatically.

3. **Run the Engine**: After building, the executable will be located in `out/build/x64-debug/Artisan2D.exe`. You can run it from there.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.