#include "Core.hpp"
#include "Engine.hpp"
#include "Input.hpp"
#include "Game.hpp"

#include <SDL2/SDL.h>

Engine* Engine::_instance = nullptr;

Engine::Engine()
{
    SDL_Log("Engine initialized!");
    // core init
    Core::Instance();
}

void Engine::Run()
{
    bool quit = false;


    while(!quit)
    {
        if (!Input::Instance()->Listen())
            quit = true;

        Game::Instance()->Update(0.0f);
        Game::Instance()->Draw();
    }

    delete _instance;
}

Engine::~Engine()
{
    Game::Instance()->Over();
    Core::Quit();
    SDL_Log("Engine quit.");
}
