#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <SDL2/SDL.h>

class Keyboard
{
    private:
        static Keyboard* _instance;
        const Uint8* _keyboard;

    private:
        Keyboard();

    public:
        static Keyboard* Instance() { return _instance = _instance != nullptr ? _instance : new Keyboard(); } 

    public:
        bool Listen(SDL_Event* event);
        bool KeyPressed(SDL_Scancode key);
        void Debug();
};

#endif
