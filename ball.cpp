#include "ball.h"
#include "game.h"
#include <iostream>

void Ball::update()
{
    lastPos = Vector2d(getdest().x, getdest().y);
    if(lastPos.x + velocity.x * 30 + 15 >= Game::game_width || lastPos.x + velocity.x * 30 <= 0 )velocity.x *=-1;
    if(lastPos.y + velocity.y * 30 + 15 >= Game::game_height || lastPos.y + velocity.y * 30 <= 0 )velocity.y *=-1;
    move(velocity.x * 30,velocity.y * 30);
}

void Ball::update(SDL_Rect b)
{
    lastPos = Vector2d(getdest().x, getdest().y);
    if(lastPos.x + velocity.x * 30 + 15 <= b.x + b.w && lastPos.x + velocity.x * 30 >= b.x  )
    {
        if(abs((int)lastPos.y + 15 - b.y) < abs((int)lastPos.y - b.y - b.h))setpos(lastPos.x,b.y - velocity.y * 30);
        else setpos(lastPos.x, b.y + b.h - velocity.y * 30);
        velocity.y *=-1;
    }
    else if(lastPos.y + velocity.y * 30 + 15 <= b.y + b.h  && lastPos.y + velocity.y * 30 >= b.y  )
    {
        if(abs((int)lastPos.x + 15 - b.x) < abs((int)lastPos.x - b.x - b.w))setpos(b.x - velocity.x * 30,lastPos.y);
        else setpos(b.x + b.w - velocity.x * 30 ,lastPos.y );
        velocity.x *=-1;
    }
    move(velocity.x * 30,velocity.y * 30);
}

void Ball::render()
{
    draw();
}