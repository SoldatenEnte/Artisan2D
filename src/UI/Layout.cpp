#include "../../include/UI/Layout.h"
#include "../../include/Graphics/Renderer.h"
#include "../../include/Colors.h"
#include <SDL2_gfxPrimitives.h>

// Implement the DrawSection function
void Layout::DrawSection(int x, int y, int w, int h, const char* text) {
    SDL_Renderer* renderer = Renderer::GetRenderer();

    // Draw rounded rectangle using SDL2_gfx
    roundedBoxRGBA(renderer, x, y, x + w, y + h, 15,
        Colors::WINDOW_COLOR.r, Colors::WINDOW_COLOR.g,
        Colors::WINDOW_COLOR.b, Colors::WINDOW_COLOR.a);

    // Placeholder for text rendering (future feature)
}

// Implement the Draw function
void Layout::Draw() {
    SDL_Renderer* renderer = Renderer::GetRenderer();
    int windowWidth, windowHeight;

    // Get the current window size
    SDL_GetWindowSize(Renderer::GetWindow(), &windowWidth, &windowHeight);

    // Set the background color to BACKGROUND and clear the renderer
    SDL_SetRenderDrawColor(renderer, Colors::BACKGROUND.r, Colors::BACKGROUND.g,
        Colors::BACKGROUND.b, Colors::BACKGROUND.a);
    SDL_RenderClear(renderer);

    int offset = 15; // Define a smaller offset

    // Calculate sizes and positions relative to the window size
    int leftWidth = (windowWidth - 3 * offset) * 0.4;  // Adjusted width for left window
    int rightWidth = (windowWidth - 3 * offset) * 0.6; // Adjusted width for right window
    int sectionHeight = windowHeight - 2 * offset;     // Height of the inner windows

    int upperHeight = (windowHeight - 3 * offset) * 0.65;
    int lowerHeight = (windowHeight - 3 * offset) * 0.35;

    // Left window
    DrawSection(offset, offset, leftWidth, sectionHeight, "Left Window");

    // Right Upper window
    DrawSection(leftWidth + offset + offset, offset, rightWidth, upperHeight, "Right Upper Window");

    // Right Lower window
    DrawSection(leftWidth + offset + offset, upperHeight + offset + offset, rightWidth, lowerHeight, "Right Lower Window");

    // Present the renderer
    SDL_RenderPresent(renderer);
}