#include <SDL.h>
#include "../include/core/Logger.h"
#include "../include/Core/Engine.h"
#include "../include/Blocks/KeyInputBlock.h"
#include "../include/Blocks/ShapeBlock.h"

int main(int argc, char* argv[]) {
    Engine engine;

    if (!engine.Init()) {
        return 1;
    }

    // Create a KeyInputBlock
    auto keyBlock = std::make_unique<KeyInputBlock>(
        SDLK_SPACE, KeyState::DOWN,
        []() { Logger::Log("Space key pressed!"); }
    );


    auto centerShapeX = std::make_unique<ShapeBlock>(
        ShapeType::RECTANGLE, 0, 0, 1000, 10, SDL_Color{ 255, 0, 0, 255 }
    );
    engine.AddBlock(std::move(centerShapeX));

    auto centerShapeY = std::make_unique<ShapeBlock>(
        ShapeType::RECTANGLE, 0, 0, 10, 1000, SDL_Color{ 0, 255, 0, 255 }
    );
    engine.AddBlock(std::move(centerShapeY));

    auto centerShapeZ = std::make_unique<ShapeBlock>(
        ShapeType::CIRCLE, 0, 0, 100, 100, SDL_Color{ 0, 0, 255, 127 }
    );
    engine.AddBlock(std::move(centerShapeZ));


    // Add the blocks to the engine
    engine.AddBlock(std::move(keyBlock));

    engine.Run();
    engine.Shutdown();

    return 0;
}