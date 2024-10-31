#include "../../include/Core/Engine.h"
#include "../../include/Core/Logger.h"
#include "../../include/Graphics/Renderer.h"
#include "../../include/UI/Layout.h"
#include "../../include/Colors.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <iostream>

Engine::Engine() : running(false) {}

bool Engine::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL Initialization Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize the renderer with maximized window
    if (!Renderer::Init("Artisan2D Engine", 1400, 750)) {
        SDL_Quit();
        return false;
    }

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable keyboard controls

    // Set up ImGui style
    ImGui::StyleColorsDark();

    // Initialize ImGui backends
    if (!ImGui_ImplSDL2_InitForSDLRenderer(Renderer::GetWindow(), Renderer::GetRenderer())) {
        std::cerr << "Failed to initialize ImGui SDL2 backend" << std::endl;
        return false;
    }

    if (!ImGui_ImplSDLRenderer2_Init(Renderer::GetRenderer())) {
        std::cerr << "Failed to initialize ImGui SDL2 Renderer backend" << std::endl;
        return false;
    }

    UpdateGameViewport();

    // Initialize Logger with an explicit path
    std::string logPath = SDL_GetBasePath();
    logPath += "artisan2d.log";
    Logger::Init(logPath);
    Logger::Log("Engine initialized successfully");
    Logger::Log("Log file created at: " + logPath);

    running = true;
    return true;
}

void Engine::Run() {
    running = true;

    Uint32 frameStart, frameTime;
    float deltaTime = 0.0f;
    Uint32 lastFrameTime = SDL_GetTicks();

    // FPS counting variables
    int frameCount = 0;
    Uint32 fpsTimer = SDL_GetTicks();
    float fps = 0.0f;

    while (running) {
        frameStart = SDL_GetTicks();

        ProcessInput();
        Update(deltaTime);
        Render();

        // FPS calculation
        frameCount++;
        if (SDL_GetTicks() - fpsTimer > 1000) {
            fps = frameCount / ((SDL_GetTicks() - fpsTimer) / 1000.0f);
            frameCount = 0;
            fpsTimer = SDL_GetTicks();

            // Log or print the FPS
            //std::cout << "FPS: " << fps << std::endl;
            // Or use the logger when implemented:
            Logger::Log("FPS: " + std::to_string(fps));
        }

        frameTime = SDL_GetTicks() - frameStart;

        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }

        Uint32 currentFrameTime = SDL_GetTicks();
        deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f;
        lastFrameTime = currentFrameTime;
    }
}

void Engine::Shutdown() {
    // Cleanup ImGui
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    Renderer::Shutdown();
    SDL_Quit();
}

void Engine::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // Let ImGui handle events first
        ImGui_ImplSDL2_ProcessEvent(&event);

        // Get ImGui IO
        ImGuiIO& io = ImGui::GetIO();

        // Only process game events if ImGui isn't capturing the mouse/keyboard
        if (!io.WantCaptureMouse && !io.WantCaptureKeyboard) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    int newWidth = event.window.data1;
                    int newHeight = event.window.data2;
                    UpdateGameViewport();
                    Renderer::HandleResize(newWidth, newHeight);
                }
            }
            // Add any other game input handling here
        }
        else {
            // ImGui wants to capture input, so still handle window events
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    int newWidth = event.window.data1;
                    int newHeight = event.window.data2;
                    UpdateGameViewport();
                    Renderer::HandleResize(newWidth, newHeight);
                }
            }
        }
    }
}

void Engine::Update(float deltaTime) {
    // Update game logic here
    for (auto& block : m_blocks) {
        block->Update();
    }
}

void Engine::Render() {
    Renderer::Clear();

    // Set background color
    SDL_SetRenderDrawColor(Renderer::GetRenderer(),
        Colors::BACKGROUND.r,
        Colors::BACKGROUND.g,
        Colors::BACKGROUND.b,
        Colors::BACKGROUND.a);
    SDL_RenderClear(Renderer::GetRenderer());

    // Render game objects
    SDL_Renderer* renderer = Renderer::GetRenderer();
    SDL_RenderSetViewport(renderer, &m_gameViewport);

    for (auto& block : m_blocks) {
        if (auto shapeBlock = dynamic_cast<ShapeBlock*>(block.get())) {
            shapeBlock->Render(renderer, m_gameViewport, m_gameScale);
        }
    }

    SDL_RenderSetViewport(renderer, nullptr);

    // Draw ImGui UI
    Layout::Draw();

    Renderer::Present();
}

void Engine::AddBlock(std::unique_ptr<Block> block) {
    m_blocks.push_back(std::move(block));
}

void Engine::UpdateGameViewport() {
    int windowWidth, windowHeight;
    SDL_GetWindowSize(Renderer::GetWindow(), &windowWidth, &windowHeight);

    int offset = windowWidth * 0.01;
    int builderWidth = (windowWidth - 3 * offset) * 0.4;
    int previewWidth = (windowWidth - 3 * offset) * 0.6;
    int previewHeight = previewWidth * 9 / 16;

    m_gameViewport.x = builderWidth + offset + offset;
    m_gameViewport.y = offset;
    m_gameViewport.w = previewWidth;
    m_gameViewport.h = previewHeight;

    // Calculate scale factors
    m_gameScale.x = static_cast<float>(m_gameViewport.w) / GAME_WIDTH;
    m_gameScale.y = static_cast<float>(m_gameViewport.h) / GAME_HEIGHT;

    // Use the smaller scale factor to maintain aspect ratio
    float scale = std::min(m_gameScale.x, m_gameScale.y);
    m_gameScale.x = m_gameScale.y = scale;

    // Adjust the viewport to maintain aspect ratio
    int scaledWidth = static_cast<int>(GAME_WIDTH * scale);
    int scaledHeight = static_cast<int>(GAME_HEIGHT * scale);

    m_gameViewport.x += (previewWidth - scaledWidth) / 2;
    m_gameViewport.y += (previewHeight - scaledHeight) / 2;
    m_gameViewport.w = scaledWidth;
    m_gameViewport.h = scaledHeight;
}
