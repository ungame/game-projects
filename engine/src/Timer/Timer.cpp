#include "Timer.hpp"
#include "Settings.hpp"

#include <SDL2/SDL.h>

Timer* Timer::_instance = nullptr;

Timer::Timer()
{
    _start = SDL_GetTicks64();
    _fps = DEFAULT_FPS;
}

void Timer::Tick(float fps)
{
    _frameTime = SDL_GetTicks64() - _start;
    _start = SDL_GetTicks64();
    _fps = fps;
}

float Timer::GetDeltaTime()
{
    return (float)_frameTime * (_fps / 1000.0F);
}

