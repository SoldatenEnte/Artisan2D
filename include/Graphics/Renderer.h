#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <string>

class Renderer {
public:
    static bool Init(const std::string& title, int width, int height);
    static void Clear();
    static void Present();
    static void Shutdown();
    static void HandleResize(int width, int height);
    static SDL_Renderer* GetRenderer() { return renderer; }
    static SDL_Window* GetWindow();

private:
    static SDL_Window* window;
    static SDL_Renderer* renderer;
};

#endif // RENDERER_H
