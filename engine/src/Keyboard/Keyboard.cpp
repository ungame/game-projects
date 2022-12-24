#include "Keyboard.hpp"

#include <SDL2/SDL.h>

Keyboard* Keyboard::_instance = nullptr;

Keyboard::Keyboard()
{
    _keyboard = SDL_GetKeyboardState(nullptr);
}

bool Keyboard::Listen(SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_KEYUP:
        case SDL_KEYDOWN:
            _keyboard = SDL_GetKeyboardState(nullptr);
            return true;
    }

    return false;
}

bool Keyboard::KeyPressed(SDL_Scancode key)
{
    return _keyboard[key] == 1;
}
