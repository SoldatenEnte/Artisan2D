#include "../../include/core/Engine.h"
#include "../../include/core/Logger.h"
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

    // Initialize Logger with an explicit path
    std::string logPath = SDL_GetBasePath();
    logPath += "artisan2d.log";
    Logger::Init(logPath);
    Logger::Log("Engine initialized successfully");
    Logger::Log("Log file created at: " + logPath);

    running = true;
    return true;
}

void Engine::Run() {
    running = true;

    Uint32 frameStart, frameTime;
    float deltaTime = 0.0f;
    Uint32 lastFrameTime = SDL_GetTicks();

    // FPS counting variables
    int frameCount = 0;
    Uint32 fpsTimer = SDL_GetTicks();
    float fps = 0.0f;

    while (running) {
        frameStart = SDL_GetTicks();

        ProcessInput();
        Update(deltaTime);
        Render();

        // FPS calculation
        frameCount++;
        if (SDL_GetTicks() - fpsTimer > 1000) {
            fps = frameCount / ((SDL_GetTicks() - fpsTimer) / 1000.0f);
            frameCount = 0;
            fpsTimer = SDL_GetTicks();

            // Log or print the FPS
            //std::cout << "FPS: " << fps << std::endl;
            // Or use the logger when implemented:
            Logger::Log("FPS: " + std::to_string(fps));
        }

        frameTime = SDL_GetTicks() - frameStart;

        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }

        Uint32 currentFrameTime = SDL_GetTicks();
        deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f;
        lastFrameTime = currentFrameTime;
    }
}

void Engine::Shutdown() {
    Renderer::Shutdown();
    SDL_Quit();
}

void Engine::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        // Handle window resizing
        else if (event.type == SDL_WINDOWEVENT) {
            if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                int newWidth = event.window.data1;
                int newHeight = event.window.data2;
                // Handle resizing logic here
                // For example, you might want to update your renderer or UI layout
                Renderer::HandleResize(newWidth, newHeight);
                Layout::HandleResize(newWidth, newHeight);
            }
        }
        // Add any other input handling here
    }
}

void Engine::Update(float deltaTime) {
    // Update game logic here
    // You can pass deltaTime to other update functions
}

void Engine::Render() {
    Renderer::Clear();

    // Your existing rendering code
    Layout::Draw();

    Renderer::Present();
}