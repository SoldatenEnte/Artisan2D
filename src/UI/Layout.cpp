#include "../../include/UI/Layout.h"
#include "../../include/Graphics/Renderer.h"
#include "../../include/Colors.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL2/SDL.h>

void Layout::Draw() {
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // Get the window size
    int window_width, window_height;
    SDL_GetWindowSize(Renderer::GetWindow(), &window_width, &window_height);

    // Define gap size
    const float GAP = 8.0f;  // Size of gap between windows

    // Calculate window dimensions with gaps
    float builder_width = (window_width * 0.375f) - (GAP * 1.5f);  // Subtract half gap from left and right
    float right_panel_width = (window_width - builder_width) - (GAP * 2.5f);  // Account for gaps
    float game_height = (window_height * 0.675f) - (GAP * 1.5f);
    float asset_height = (window_height * 0.325f) - (GAP * 1.5f);

    // Convert SDL_Color to ImGui colors
    ImVec4 backgroundColor(
        Colors::BACKGROUND.r / 255.0f,
        Colors::BACKGROUND.g / 255.0f,
        Colors::BACKGROUND.b / 255.0f,
        Colors::BACKGROUND.a / 255.0f
    );

    ImVec4 windowColor(
        Colors::WINDOW_COLOR.r / 255.0f,
        Colors::WINDOW_COLOR.g / 255.0f,
        Colors::WINDOW_COLOR.b / 255.0f,
        Colors::WINDOW_COLOR.a / 255.0f
    );

    // Set up the style
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 8.0f;  // Add rounded corners to windows
    style.WindowBorderSize = 0.0f;
    style.Colors[ImGuiCol_WindowBg] = windowColor;
    style.Colors[ImGuiCol_Border] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);

    // Set background color for the entire ImGui context
    ImGui::PushStyleColor(ImGuiCol_WindowBg, windowColor);

    // Clear the renderer with the background color
    SDL_SetRenderDrawColor(
        Renderer::GetRenderer(),
        Colors::BACKGROUND.r,
        Colors::BACKGROUND.g,
        Colors::BACKGROUND.b,
        Colors::BACKGROUND.a
    );
    SDL_RenderClear(Renderer::GetRenderer());

    // Common window flags
    ImGuiWindowFlags window_flags =
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize;

    // Builder Window (Left Panel) - add gap from left and top
    ImGui::SetNextWindowPos(ImVec2(GAP, GAP));
    ImGui::SetNextWindowSize(ImVec2(builder_width, window_height - (GAP * 2)));
    ImGui::Begin("Builder Window", nullptr, window_flags);
    ImGui::Text("Block Builder");
    // Content
    ImGui::End();

    // Game Window (Right Top) - position after builder window plus gap
    ImGui::SetNextWindowPos(ImVec2(builder_width + (GAP * 2), GAP));
    ImGui::SetNextWindowSize(ImVec2(right_panel_width, game_height));
    ImGui::Begin("Game Window", nullptr, window_flags);
    ImGui::Text("Game Viewer");
    // Content
    ImGui::End();

    // Block Window (Right Bottom) - position below game window plus gap
    ImGui::SetNextWindowPos(ImVec2(builder_width + (GAP * 2), game_height + (GAP * 2)));
    ImGui::SetNextWindowSize(ImVec2(right_panel_width, asset_height));
    ImGui::Begin("Block Window", nullptr, window_flags);
    ImGui::Text("Block Library");
    // Content
    ImGui::End();

    // Pop the style color we pushed earlier
    ImGui::PopStyleColor();

    // Render
    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), Renderer::GetRenderer());
}

void Layout::HandleResize(int width, int height) {
    // The windows will automatically update their positions and sizes
    // on the next frame based on the new window dimensions
}