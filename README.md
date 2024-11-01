<table style="border-collapse: collapse; width: auto;">
  <tr>
    <td style="border: none; vertical-align: middle;">
      <img src="/assets/artisan2d_logo_1024x.png" alt="Artisan2D Logo" width="50" />
    </td>
    <td style="border: none;">
      <h1 style="margin: 0;">Artisan2D</h1>
    </td>
  </tr>
</table>

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

### Installing SDL2 and ImGui

To install SDL2, ImGui, and other dependencies, use the following commands:

```bash
vcpkg install sdl2 sdl2-image sdl2-ttf sdl2-gfx imgui[sdl2-binding,sdl2-renderer-binding]
vcpkg integrate install
```

> **Note:** `vcpkg integrate install` will configure Visual Studio to automatically detect and link dependencies installed with vcpkg.

### Cloning the Repository

Clone the Artisan2D repository to your local machine:

```bash
git clone https://github.com/soldatenente/Artisan2D.git
cd Artisan2D
```

### Configuring the Project

1. **Configure with CMake**:
   - Open a terminal in the project directory.
   - Run the following commands to set up the project using `vcpkg`:

     ```bash
     cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path-to-vcpkg]/scripts/buildsystems/vcpkg.cmake
     ```

2. **Build the Project**:
   - Open the solution in Visual Studio or run `cmake --build build` from the terminal.

3. **Run the Engine**: After building, the executable will be located in the `build` directory. You can run it from there.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
