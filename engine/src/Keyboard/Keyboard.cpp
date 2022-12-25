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

void Keyboard::Debug()
{
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_UP))
    {
        SDL_Log("[UP]");
    }
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_RIGHT))
    {
        SDL_Log("[RIGHT]");
    }
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_LEFT))
    {
        SDL_Log("[LEFT]");
    }
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_DOWN))
    {
        SDL_Log("[DOWN]");
    }
}
