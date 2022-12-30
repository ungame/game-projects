#include "Core.hpp"
#include "Settings.hpp"
#include "Engine.hpp"
#include "Input.hpp"
#include "Game.hpp"
#include "Time.hpp"
#include "Timer.hpp"

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
    
    float deltaTime = Timer::Instance()->GetDeltaTime();
    
    Time* start = new Time(); 
    int frameCounter = 0;

    while(!quit)
    {

        if (!Input::Instance()->Listen())
            quit = true;


        deltaTime = Timer::Instance()->GetDeltaTime();

        Game::Instance()->Update(deltaTime);
        Game::Instance()->Draw();

        //SDL_Delay(1000/DEFAULT_FPS_SIMULATION);

        Timer::Instance()->Tick();

        if (Time::Since(start) >= 1.0)
        {
            SDL_Log("DeltaTime=%f, FPS=%d", deltaTime, frameCounter);
            start = new Time();
            frameCounter = 0;
        }
        else
        {
            frameCounter++;
        }
    }

    delete _instance;
}

Engine::~Engine()
{
    Game::Instance()->Over();
    Core::Quit();
    SDL_Log("Engine quit.");
}
