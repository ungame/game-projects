#ifndef GAME_HPP
#define GAME_HPP

#include "Time.hpp"

class Game
{
    private:
        static Game* _instance;
        Time* _started;

    private:
        Game() { _started = new Time(); }

    public:
        static Game* Instance() { return _instance = _instance != nullptr ? _instance : new Game(); }

    public:
        void Update(float deltaTime);
        void Draw();
};

#endif
