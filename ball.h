#pragma once
#include "object.h"
#include "vector2d.h"

class Ball: public Object {
public:
    Vector2d velocity = {0.1,0.2};
    Vector2d lastPos;
    void update();
    void update(SDL_Rect b);
    void render();
    
};