// Layout.cpp
#include "../../include/UI/Layout.h"
#include "../../include/Graphics/Renderer.h"
#include "../../include/Colors.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <SDL2/SDL.h>

namespace {
    float testValue = 0.0f;
}

void Layout::Draw() {
    // Start new ImGui frame
    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // Create a simple window with explicit size and position
    ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImVec2(50, 50), ImGuiCond_FirstUseEver);

    ImGui::Begin("Hello ImGui!");

    ImGui::Text("Welcome to Artisan2D!");
    ImGui::Text("This window should now be interactive!");
    ImGui::Spacing();

    ImGui::SliderFloat("Test Slider", &testValue, 0.0f, 100.0f);

    if (ImGui::Button("Click Me!")) {
        testValue = 50.0f;
    }

    ImGui::End();

    // Render
    ImGui::Render();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), Renderer::GetRenderer());
}

void Layout::HandleResize(int width, int height) {
    // ImGui handles resizing automatically
}