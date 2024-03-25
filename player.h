#pragma once
#include "Object.h"

class Player: public object {
public:
    void input();
    int vx = 0,vy = 0;
    
};