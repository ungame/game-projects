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
    _object->SetDirectionX(0);
    _object->SetDirectionY(0);

    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_LEFT))
       _object->SetDirectionX(BACKWARD_DIRECTION); 
    
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_RIGHT))
        _object->SetDirectionX(FORWARD_DIRECTION);

    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_UP))
        _object->SetDirectionY(UPWARD_DIRECTION);

    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_DOWN))
        _object->SetDirectionY(DOWNWARD_DIRECTION);

    float x = _object->GetX() + (DEFAULT_SPEED_X * deltaTime * _object->GetDirectionX());
    float y = _object->GetY() + (DEFAULT_SPEED_Y * deltaTime * _object->GetDirectionY());
    _object->SetX(x);
    _object->SetY(y);

    int right = _object->GetX() + _object->GetWidth();
    
    if (right >= DEFAULT_SCREEN_WIDTH)
        _object->SetX(_object->GetX() - (right - DEFAULT_SCREEN_WIDTH));


    if (_object->GetX() < 0)
        _object->SetX(0);


    int bottom = _object->GetY() + _object->GetHeight();
    if (bottom >= DEFAULT_SCREEN_HEIGHT)
        _object->SetY(_object->GetY() - (bottom - DEFAULT_SCREEN_HEIGHT));

    if (_object->GetY() < 0)
        _object->SetY(0);


    SDL_Log("X=%f, Y=%f", _object->GetX(), _object->GetY());

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
