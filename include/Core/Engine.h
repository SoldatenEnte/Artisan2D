// include/Core/Engine.h
#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <memory>
#include <SDL.h>
#include "../Blocks/Block.h"
#include "../Blocks/ShapeBlock.h"

class Engine {
public:
    Engine();
    bool Init();
    void Run();
    void Shutdown();

    void AddBlock(std::unique_ptr<Block> block);

private:
    bool running;
    const int FPS = 60;
    const int FRAME_DELAY = 1000 / FPS;

    std::vector<std::unique_ptr<Block>> m_blocks;
    SDL_Rect m_gameViewport;
    SDL_FPoint m_gameScale;

    const int GAME_WIDTH = 1920;
    const int GAME_HEIGHT = 1080;

    void ProcessInput();
    void Update(float deltaTime);
    void Render();
    void UpdateGameViewport();
};

#endif // ENGINE_H