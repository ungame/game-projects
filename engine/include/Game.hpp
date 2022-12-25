#ifndef GAME_HPP
#define GAME_HPP

#include "Time.hpp"
#include "Object.hpp"
#include "Color.hpp"

class Game
{
    private:
        static Game* _instance;

        Time* _started;
        Color* _background;
        Object* _object;

    private:
        Game(); 

    public:
        static Game* Instance() { return _instance = _instance != nullptr ? _instance : new Game(); }

    public:
        void Update(float deltaTime);
        void Draw();
        void Over();
};

#endif
