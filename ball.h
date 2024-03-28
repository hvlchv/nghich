#pragma once
#include "object.h"
#include "vector2d.h"

class Ball: public Object {
public:
    Vector2d velocity = {0.1,0.2};
    Vector2d lastPos;
    double Min = 0.1, Max = 0.2;
    void reVelocity();
    void update();
    void update(SDL_Rect b);
    void render();
    
};