#pragma once
#include "object.h"

class Player: public Object {
public:
    void update();
    void render();
    bool Left,Right;
    int vx = 0,vy = 0;
    // dest.x += x;
    // dest.y += y;
    // if(dest.x + dest.w > Game::game_width) dest.x = Game::game_width - dest.w;
    // if(dest.x < 0) dest.x = 0;
    
};