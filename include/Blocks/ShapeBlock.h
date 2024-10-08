#pragma once

#include "Block.h"
#include <SDL.h>

enum class ShapeType {
    RECTANGLE,
    CIRCLE
    // Add more shapes as needed
};

class ShapeBlock : public Block {
public:
    ShapeBlock(ShapeType type, float x, float y, float width, float height, SDL_Color color);
    void Update() override;
    void Render(SDL_Renderer* renderer, const SDL_Rect& viewportRect, const SDL_FPoint& scale);

private:
    ShapeType m_type;
    float m_x, m_y, m_width, m_height;
    SDL_Color m_color;
};