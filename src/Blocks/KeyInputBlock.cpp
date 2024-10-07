#include "../../include/Blocks/KeyInputBlock.h"
#include "../../include/Core/Logger.h"

KeyInputBlock::KeyInputBlock(SDL_Keycode key, KeyState state, std::function<void()> action)
    : m_key(key), m_state(state), m_action(action) {}

void KeyInputBlock::Update() {
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    bool isKeyPressed = keyState[SDL_GetScancodeFromKey(m_key)];

    switch (m_state) {
    case KeyState::DOWN:
        if (isKeyPressed && !m_keyWasPressed) {
            m_action();
        }
        break;
    case KeyState::UP:
        if (!isKeyPressed && m_keyWasPressed) {
            m_action();
        }
        break;
    case KeyState::HOLD:
        if (isKeyPressed) {
            m_action();
        }
        break;
    }

    m_keyWasPressed = isKeyPressed;
}