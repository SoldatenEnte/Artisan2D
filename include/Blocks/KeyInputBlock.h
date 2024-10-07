#pragma once

#include "Block.h"
#include <SDL.h>

enum class KeyState {
    DOWN,
    UP,
    HOLD
};

class KeyInputBlock : public Block {
public:
    KeyInputBlock(SDL_Keycode key, KeyState state, std::function<void()> action);
    void Update() override;

private:
    SDL_Keycode m_key;
    KeyState m_state;
    std::function<void()> m_action;
    bool m_keyWasPressed = false;
};
