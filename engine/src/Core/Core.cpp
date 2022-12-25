#include "Settings.hpp"
#include "Core.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Core* Core::_instance = nullptr;

Core::Core()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error on initialize sdl: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    int imgInitted = IMG_Init(imgFlags)&imgFlags;

    if (imgInitted != imgFlags)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error on initialize sdl support for images: %s", IMG_GetError());
        exit(EXIT_FAILURE);
    }

    _window = SDL_CreateWindow(DEFAULT_SCREEN_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (_window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error on create window: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "error on create renderer: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Log("Core initialized!");
}

Core::~Core()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
    SDL_Log("Core quit.");
}
