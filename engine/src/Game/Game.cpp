#include "Game.hpp"
#include "Core.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Time.hpp"
#include "Color.hpp"
#include "Settings.hpp"

#include <SDL2/SDL.h>

Game* Game::_instance = nullptr;

Game::Game()
{
    _started = new Time();
    _background = Color::White();
    _object = new Object(50, 50, 0, 0, Color::Red());

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Game started: %s", _started->String());
}

void Game::Update(float deltaTime)
{
    SDL_FPoint direction = { 0, 0 };

    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_LEFT))
        direction.x = -1;
    
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_RIGHT))
        direction.x = 1;

    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_UP))
        direction.y = -1;

    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_DOWN))
        direction.y = 1;

    float x = _object->GetX() + DEFAULT_SPEED_X * direction.x;
    float y = _object->GetY() + DEFAULT_SPEED_Y * direction.y;
    _object->SetX(x);
    _object->SetY(y);

    //Keyboard::Instance()->Debug();
    //Mouse::Instance()->Debug();
}

void Game::Draw()
{
    // draw game brackground
    SDL_Color bg = _background->RGBA();
    SDL_SetRenderDrawColor(Core::Instance()->GetRenderer(), bg.r, bg.g, bg.b, bg.a);
    SDL_RenderClear(Core::Instance()->GetRenderer());

    // draw object
    _object->Draw();

    SDL_RenderPresent(Core::Instance()->GetRenderer());
}

void Game::Over()
{
    Time* finished = new Time();
    double elapsed = Time::Since(_started);

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Game finished: %s. %f seconds", finished->String(), elapsed);
    
    delete finished;
    delete _background;
    delete _started;
    delete _instance;
}
