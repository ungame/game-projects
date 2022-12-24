#include "Mouse.hpp"

#include <SDL2/SDL.h>

Mouse* Mouse::_instance = nullptr;

Mouse::Mouse()
{
    _cursor = { 0, 0 };
    _button = 0;
}

bool Mouse::Listen(SDL_Event* event)
{
    switch(event->type)
    {
        case SDL_MOUSEMOTION:
            _cursor.x = event->motion.x;
            _cursor.y = event->motion.y;
            return true;

        case SDL_MOUSEBUTTONDOWN:
            _button = event->button.button;
            return true;

        case SDL_MOUSEBUTTONUP:
            _button = 0;
            return true;
    }

    return false;
}

bool Mouse::ButtonPressed(MouseButton button)
{
    switch (button)
    {
        case MouseButton::Right:
            return _button == SDL_BUTTON_RIGHT;
        case MouseButton::Left:
            return _button == SDL_BUTTON_LEFT;
        case MouseButton::Middle:
            return _button == SDL_BUTTON_MIDDLE;
        case MouseButton::X1:
            return _button == SDL_BUTTON_X1;
        case MouseButton::X2:
            return _button == SDL_BUTTON_X2;
    }

    return false;
}
