#include <SDL.h>
#include "../include/Core/Engine.h"

int main(int argc, char* argv[]) {
    // Create an instance of the engine
    Engine engine;

    // Initialize the engine
    if (!engine.Init()) {
        return 1;
    }

    // Run the main loop
    engine.Run();

    // Shutdown the engine
    engine.Shutdown();

    return 0;
}