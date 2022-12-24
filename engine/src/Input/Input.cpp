#include "Input.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"

#include <SDL2/SDL.h>

Input* Input::_instance = nullptr;

bool Input::Listen()
{
    SDL_Event event;
    bool isListening = true;

    while(SDL_PollEvent(&event))
    {
        Keyboard::Instance()->Listen(&event);
        Mouse::Instance()->Listen(&event);
    
        if (event.type == SDL_QUIT)
            isListening = false;
    }

    return isListening;
}
