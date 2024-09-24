#include "../../include/Graphics/Renderer.h"
#include <iostream>

SDL_Window* Renderer::window = nullptr;
SDL_Renderer* Renderer::renderer = nullptr;

bool Renderer::Init(const std::string& title, int width, int height) {
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED
    );

    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return false;
    }

    return true;
}

SDL_Window* Renderer::GetWindow() {
    return window;  // Return the window pointer
}

void Renderer::Clear() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void Renderer::Present() {
    SDL_RenderPresent(renderer);
}

void Renderer::Shutdown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Renderer::HandleResize(int width, int height) {
    SDL_SetWindowSize(window, width, height);
    SDL_RenderSetLogicalSize(renderer, width, height);
    // Might want to add additional logic here, such as updating any
    // cached window dimensions or adjusting rendering parameters
}
