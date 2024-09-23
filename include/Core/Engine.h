#ifndef ENGINE_H
#define ENGINE_H

class Engine {
public:
    Engine();
    bool Init();        // Initialize the engine
    void Run();         // Run the main loop
    void Shutdown();    // Shutdown the engine

private:
    bool running;       // Flag to keep the engine running
};

#endif // ENGINE_H