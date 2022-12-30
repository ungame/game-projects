#include "Object.hpp"
#include "Color.hpp"
#include "Core.hpp"

#include <SDL2/SDL.h>

Object::Object(int width, int height, float x, float y, Color* c)
{
    _width = width;
    _height = height;
    _position = SDL_FPoint{x, y};
    _direction = SDL_Point{ 0, 0 };
    _color = c;
}

void Object::Draw()
{
    SDL_Color c = _color->RGBA();
    SDL_SetRenderDrawColor(Core::Instance()->GetRenderer(), c.r, c.g, c.b, c.a);
    
    int x = _position.x; 
    int y = _position.y;
    SDL_Rect rect = {x, y, _width, _height};
    SDL_RenderDrawRect(Core::Instance()->GetRenderer(), &rect);
    SDL_RenderFillRect(Core::Instance()->GetRenderer(), &rect);
}

Object::~Object()
{
    delete _color;
}
