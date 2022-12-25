#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SDL2/SDL.h>

#include "Color.hpp"

class Object
{
    private:
        int _width;
        int _height;
        SDL_FPoint _position;
        Color* _color;

    public:
        Object(int width, int height, float x, float y, Color* c = Color::Grey());
        void Draw();
        ~Object();

    public:
        inline void SetX(float x) { _position.x = x; }
        inline float GetX() { return _position.x; }
        inline void SetY(float y) { _position.y = y; }
        inline float GetY() { return _position.y; }
};

#endif
