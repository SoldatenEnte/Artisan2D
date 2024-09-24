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
    const int FPS = 60;
    const int FRAME_DELAY = 1000 / FPS;

    void ProcessInput();
    void Update(float deltaTime);
    void Render();
};

#endif // ENGINE_H