#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Time.hpp"

class Engine
{
    private:
        static Engine* _instance;
        Time* _startedAt;

    private:
        Engine();

    public:
        static Engine* Instance() { return _instance = _instance != nullptr ? _instance : new Engine(); }

    public:
        ~Engine();
        bool Listen();
        void Update();
        void Draw();
        void Quit();

};

#endif
