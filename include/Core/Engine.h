#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <memory>
#include "../Blocks/Block.h"

class Engine {
public:
    Engine();
    bool Init();        // Initialize the engine
    void Run();         // Run the main loop
    void Shutdown();    // Shutdown the engine

    void AddBlock(std::unique_ptr<Block> block);

private:
    bool running;       // Flag to keep the engine running
    const int FPS = 60;
    const int FRAME_DELAY = 1000 / FPS;

    std::vector<std::unique_ptr<Block>> m_blocks;

    void ProcessInput();
    void Update(float deltaTime);
    void Render();
};

#endif // ENGINE_H