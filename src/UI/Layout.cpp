#include "../../include/UI/Layout.h"
#include "../../include/Graphics/Renderer.h"
#include "../../include/Colors.h"
#include <SDL2_gfxPrimitives.h>

// Implement the DrawSection function
void Layout::DrawSection(int x, int y, int w, int h, float r, const char* text) {
    SDL_Renderer* renderer = Renderer::GetRenderer();

    // Draw rounded rectangle using SDL2_gfx
    roundedBoxRGBA(renderer, x, y, x + w, y + h, r,
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

    int offset = windowWidth * 0.01;

    // Calculate sizes and positions relative to the window size
    int builderWidth = (windowWidth - 3 * offset) * 0.4;  // Width for the Builder
    int previewWidth = (windowWidth - 3 * offset) * 0.6;  // Width for the Game Preview Area
    int sectionHeight = windowHeight - 2 * offset;        // Height of the inner windows

    int previewHeight = previewWidth * 9 / 16;            // Height for the Game Preview Area
    int blockSelectionHeight = windowHeight - previewHeight - 3 * offset; // Height for the Block Selection Area

    // Builder (Left Window)
    DrawSection(offset, offset, builderWidth, sectionHeight, offset, "Builder");

    // Game Preview Area (Right Upper Window)
    DrawSection(builderWidth + offset + offset, offset, previewWidth, previewHeight, offset, "Game Preview");

    // Block Selection Area (Right Lower Window)
    DrawSection(builderWidth + offset + offset, previewHeight + offset + offset, previewWidth, blockSelectionHeight, offset, "Block Selection");

    // Present the renderer
    SDL_RenderPresent(renderer);
}

