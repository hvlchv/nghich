#include "ball.h"
#include "game.h"
#include <iostream>

void Ball::reVelocity() {
    double Vx = velocity.x;
    double Vy = velocity.y;

    if(Vx < 0) Vx *= -1;
    if(Vy < 0) Vy *= -1;

    if(Vx < Min) {
        if(velocity.x < 0) velocity.x = -Min;
        else velocity.x = Min;
    }
    else if(Vx > Max) {
        if(velocity.x < 0) velocity.x = -Max;
        else velocity.x = Max;
    }

    if(Vy < Min) {
        if(velocity.y < 0) velocity.y = -Min;
        else velocity.y = Min;
    }
    else if(Vy > Max) {
        if(velocity.y < 0) velocity.y = -Max;
        else velocity.y = Max;
    }

    Vx = velocity.x;
    Vy = velocity.y;

    if(Vx<0)Vx *=-1;
    if(Vy<0)Vy *=-1;
   // std::cout<<Vx<<' '<<Vy<<'\n';
}

void Ball::update() {

    lastPos = Vector2d(getdest().x, getdest().y);
    bool ok = false;

    if(lastPos.x + velocity.x * 30 + 15 >= Game::game_width || lastPos.x + velocity.x * 30 <= 0 ) {
        velocity.x *= -1.2;
        ok = true;
    }

    if(lastPos.y + velocity.y * 30 + 15 >= Game::game_height || lastPos.y + velocity.y * 30 <= 0 ) {
        velocity.y *= -1.2;
        ok = true;
    }

    if(!ok && Game::frame%15 == 0) {
        velocity.x*=0.9;
        velocity.y*=0.9;
    }

    reVelocity();
    move(velocity.x * 30, velocity.y * 30);
    
}

void Ball::update(SDL_Rect b) {

    lastPos = Vector2d(getdest().x, getdest().y);
    int inX,inY;
    

    // if(lastPos.x  <= b.x + b.w && lastPos.x +15 >= b.x  )inX = true;
    inX = std::min(lastPos.x + 15 - b.x, b.x + b.w - lastPos.x);
    inY = std::min(lastPos.y + 15 - b.y, b.y + b.h - lastPos.y);

    if(lastPos.x + 15 <= b.x + b.w && lastPos.x >= b.x  ) {
        velocity.y *= -1.2;
        if(abs((int)lastPos.y + 15 - b.y) < abs((int)lastPos.y - b.y - b.h)) setpos(lastPos.x,b.y - 15);
        else setpos(lastPos.x,b.y+b.h);
    }

    else if(lastPos.y + 15 <= b.y + b.h  && lastPos.y  >= b.y  ) {
        if(abs((int)lastPos.x + 15 - b.x) < abs((int)lastPos.x - b.x - b.w)) setpos(b.x - 15,lastPos.y);
        else setpos(b.x + b.w,lastPos.y);
        velocity.x *= -1.2;
    }

    else {

        if(inX > inY ) {
            velocity.y *= -1.2;
            if(abs((int)lastPos.y + 15 - b.y) < abs((int)lastPos.y - b.y - b.h))setpos(lastPos.x,b.y - 15);
            else setpos(lastPos.x,b.y+b.h);
        }

        else if(inY > inX ) {
            if(abs((int)lastPos.x + 15 - b.x) < abs((int)lastPos.x - b.x - b.w))setpos(b.x - 15,lastPos.y);
            else setpos(b.x + b.w,lastPos.y);
            velocity.x *= -1.2;
        }

        else {
            int X,Y;

            if(abs((int)lastPos.y + 15 - b.y) < abs((int)lastPos.y - b.y - b.h)) {
                Y = b.y - 15;
            }
            else Y = b.y+b.h;

            if(abs((int)lastPos.x + 15 - b.x) < abs((int)lastPos.x - b.x - b.w)) {
                X = b.x - 15;
            }
            else X = b.x + b.w;

            setpos(X,Y);
            velocity.y *= -1.5;
            velocity.x *= -1.5;
        }
        //SDL_Delay(1000);
    }

    reVelocity();
    move(velocity.x * 30,velocity.y * 30);
    //std::cout<<fullX<<' '<<fullY<<'\n';
    //SDL_Delay(1000);
    //move(velocity.x * 30,velocity.y * 30);
}

void Ball::render() {
    draw();
}