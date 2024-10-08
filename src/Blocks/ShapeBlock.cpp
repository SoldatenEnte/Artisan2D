// src/Blocks/ShapeBlock.cpp
#include "../../include/Blocks/ShapeBlock.h"
#include "../../include/Graphics/Renderer.h"
#include <SDL2_gfxPrimitives.h>
#include <cmath>

ShapeBlock::ShapeBlock(ShapeType type, float x, float y, float width, float height, SDL_Color color)
    : m_type(type), m_x(x), m_y(y), m_width(width), m_height(height), m_color(color) {}

void ShapeBlock::Update() {
    // Add any update logic here if needed
}

void ShapeBlock::Render(SDL_Renderer* renderer, const SDL_Rect& viewportRect, const SDL_FPoint& scale) {
    // Convert game coordinates to viewport coordinates
    float scaledWidth = m_width * scale.x;
    float scaledHeight = m_height * scale.y;

    // Calculate the position within the viewport
    float adjustedX = (m_x * scale.x) + (viewportRect.w / 2.0f) - (scaledWidth / 2.0f);
    float adjustedY = (viewportRect.h / 2.0f) - (m_y * scale.y) - (scaledHeight / 2.0f); // Invert Y-axis

    // Ensure the shape is within the viewport
    if (adjustedX + scaledWidth < 0 || adjustedY + scaledHeight < 0 ||
        adjustedX > viewportRect.w || adjustedY > viewportRect.h) {
        return; // Shape is outside the viewport, don't render
    }

    switch (m_type) {
    case ShapeType::RECTANGLE:
        boxRGBA(renderer,
            static_cast<Sint16>(adjustedX), static_cast<Sint16>(adjustedY),
            static_cast<Sint16>(adjustedX + scaledWidth), static_cast<Sint16>(adjustedY + scaledHeight),
            m_color.r, m_color.g, m_color.b, m_color.a);
        break;
    case ShapeType::CIRCLE:
        filledCircleRGBA(renderer,
            static_cast<Sint16>(adjustedX + scaledWidth / 2),
            static_cast<Sint16>(adjustedY + scaledHeight / 2),
            static_cast<Sint16>(std::min(scaledWidth, scaledHeight) / 2),
            m_color.r, m_color.g, m_color.b, m_color.a);
        break;
    }
}