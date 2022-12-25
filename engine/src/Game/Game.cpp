#include "Game.hpp"
#include "Core.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"

Game* Game::_instance = nullptr;

void Game::Update(float deltaTime)
{
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_UP))
    {
        SDL_Log("[UP]");
    }
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_RIGHT))
    {
        SDL_Log("[RIGHT]");
    }
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_LEFT))
    {
        SDL_Log("[LEFT]");
    }
    if (Keyboard::Instance()->KeyPressed(SDL_SCANCODE_DOWN))
    {
        SDL_Log("[DOWN]");
    }
    if (Mouse::Instance()->ButtonPressed(MouseButton::Right))
    {
        SDL_Log("[MOUSE_BUTTON_RIGHT]");
    }
    if (Mouse::Instance()->ButtonPressed(MouseButton::Left))
    {
        SDL_Log("[MOUSE_BUTTON_LEFT]");
    }
    if (Mouse::Instance()->ButtonPressed(MouseButton::Middle))
    {
        SDL_Log("[MOUSE_BUTTON_MIDDLE]");
    }
    if (Mouse::Instance()->ButtonPressed(MouseButton::X1))
    {
        SDL_Log("[MOUSE_BUTTON_X1]");
    }
    if (Mouse::Instance()->ButtonPressed(MouseButton::X2))
    {
        SDL_Log("[MOUSE_BUTTON_X2]");
    }

}

void Game::Draw()
{
    SDL_RenderClear(Core::Instance()->GetRenderer());
    SDL_RenderPresent(Core::Instance()->GetRenderer());
}
