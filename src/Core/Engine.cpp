#include "../../include/core/Engine.h"
#include "../../include/Graphics/Renderer.h"
#include "../../include/UI/Layout.h"
#include <iostream>

Engine::Engine() : running(false) {}

bool Engine::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL Initialization Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize the renderer with maximized window
    if (!Renderer::Init("Artisan2D Engine", 1400, 750)) {
        SDL_Quit();
        return false;
    }

    running = true;
    return true;
}

void Engine::Run() {
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            // Handle window resizing
            else if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    // Optionally, you can handle resizing logic here
                    int newWidth = event.window.data1;
                    int newHeight = event.window.data2;
                    // You can use newWidth and newHeight as needed
                }
            }
        }

        // Draw the layout
        Layout::Draw();

        SDL_Delay(16);  // Roughly 60 FPS
    }
}


void Engine::Shutdown() {
    Renderer::Shutdown();
    SDL_Quit();
}