#include <SDL.h>
#include "../include/core/Logger.h"
#include "../include/Core/Engine.h"
#include "../include/Blocks/KeyInputBlock.h"

int main(int argc, char* argv[]) {
    // Create an instance of the engine
    Engine engine;

    // Initialize the engine
    if (!engine.Init()) {
        return 1;
    }

    // Create a KeyInputBlock
    auto keyBlock = std::make_unique<KeyInputBlock>(
        SDLK_SPACE, KeyState::DOWN,
        []() { Logger::Log("Space key pressed!"); }
    );

    // Add the block to the engine
    engine.AddBlock(std::move(keyBlock));

    // Run the main loop
    engine.Run();

    // Shutdown the engine
    engine.Shutdown();

    return 0;
}