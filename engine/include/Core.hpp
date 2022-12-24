#ifndef CORE_HPP
#define CORE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Core
{
    private:
        static Core* _instance;
        SDL_Window* _window;
        SDL_Renderer* _renderer;

    private:
        Core();

    public:
        ~Core();

    public:
        static Core* Instance() { return _instance = _instance != nullptr ? _instance : new Core(); }
        static void Quit() { delete _instance; } 

    public:
        SDL_Window* GetWindow() const { return _window; }
        SDL_Renderer* GetRenderer() const { return _renderer; }
};

#endif
