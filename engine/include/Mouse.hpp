#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <SDL2/SDL.h>

enum MouseButton 
{
    Right,
    Middle,
    Left,
    X1,
    X2
};

class Mouse
{
    private:
        static Mouse* _instance;
        SDL_Point _cursor;
        Uint8 _button;

    public:
        static Mouse* Instance() { return _instance = _instance != nullptr ? _instance : new Mouse(); }

    private:
        Mouse(); 

    public:
        bool Listen(SDL_Event* event);
        SDL_Point GetCursor() { return _cursor; }
        bool ButtonPressed(MouseButton button);
};

#endif
