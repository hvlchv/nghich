#include "object.h"
#include "TextureManager.h"
#include <bits/stdc++.h>
#include "game.h"

void Object::setlength() {
    
}

void Object::init(const char* path) {
    setTex(path);
    setpos(0,0);

}

void Object::move(int x,int y)
{
    dest.x += x;
    dest.y += y;
    if(dest.x + dest.w > Game::game_width) dest.x = Game::game_width - dest.w;
    if(dest.x < 0) dest.x = 0;
}


void Object::draw() {

    SDL_Rect Dest = {dest.x, dest.y, int(dest.w * scale), int(dest.h * scale)};
    textureManager::DrawImage(texture,src,dest);
}
void Object::setsrc(SDL_Rect sr) {
    src = sr;
}
void Object::setdest(SDL_Rect des) {
    dest = des;
}
void Object::setTex(const char* path) {
    texture = textureManager::LoadImage(path, src);
    dest = src;
    
}
void Object::setscale(double sca) {
    scale = sca;
    
}
void Object::setwidth(int w)
{
    dest.w = w;
}
void Object::setpos(int x, int y) {
    dest.x = x;
    dest.y = y;
}
SDL_Rect Object::getsrc() {
    return src;
}
SDL_Rect Object::getdest() {
    return dest;
}
double Object::getscale() {
    return scale;
}

bool Object:: collision(SDL_Rect A )
{
    SDL_Rect B = dest;
    return !(   A.x > B.x + B.w||
                A.y > B.y + B.h||
                B.x > A.x + A.w||
                B.y > A.y + A.h);
}