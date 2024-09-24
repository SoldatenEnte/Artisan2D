#ifndef COLORS_H
#define COLORS_H

#include <SDL.h>

namespace Colors {
    const SDL_Color BACKGROUND = { 32, 34, 37, 255 }; // Engine background color
    const SDL_Color WINDOW_COLOR = { 38, 40, 43, 255 }; // Section background color
    const SDL_Color COLOR_1 = {71, 212, 155, 255}; // Cyan
    const SDL_Color COLOR_2 = { 119, 79, 235, 255 }; // Purple
    const SDL_Color WHITE = { 255, 255, 255, 255 };
    const SDL_Color BLACK = { 0, 0, 0, 255 };
    const SDL_Color GREY = { 200, 200, 200, 255 };
    const SDL_Color BLUE = { 0, 0, 255, 255 };
    // Add more colors as needed
}

#endif // COLORS_H