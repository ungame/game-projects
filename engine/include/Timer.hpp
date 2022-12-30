#ifndef TIMER_HPP
#define TIMER_HPP

#include <SDL2/SDL.h>

#include "Settings.hpp"

class Timer
{
    private:
        static Timer* _instance;
        Uint64 _start;
        Uint64 _frameTime;
        float _fps;

    private:
        Timer();

    public:
        static Timer* Instance() { return _instance = _instance != nullptr ? _instance : new Timer(); }
    
    public:
        void Tick(float fps = DEFAULT_FPS);
        float GetDeltaTime();

};

#endif
