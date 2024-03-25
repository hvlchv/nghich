#include "Object.h"
#include "TextureManager.h"
#include <iostream>
#include "game.h"

void object::setlength() {
    
}

void object::init(const char* path) {
    setTex(path);
    setpos(0,0);

}

void object::update(int x, int y) {
    // if(Game::event.type == SDL_KEYDOWN)
    // {
    //     switch(Game::event.key.keysym.sym )
    //     {
    //         case SDLK_a:
    //         dest.x -= 5;
    //         break;
    //         case SDLK_d:
    //         dest.x += 5;
    //         break;
    //     }
    // }
    dest.x += x;
    dest.y += y;
    if(dest.x + dest.w > Game::Width) dest.x = Game::Width - dest.w;
    if(dest.x < 0) dest.x = 0;
    dest.w = src.w * scale;
    dest.h = src.h * scale;
}
void object::render() {
    textureManager::DrawImage(texture,src,dest);
}
void object::setsrc(SDL_Rect sr) {
    src = sr;
}
void object::setdest(SDL_Rect des) {
    dest = des;
}
void object::setTex(const char* path) {
    texture = textureManager::LoadImage(path, src);
    
    dest.w = src.w * scale;
    dest.h = src.w * scale;
    std::cout << dest.x << ' ' << dest.y;
}
void object::setscale(double sca) {
    scale = sca;
}
void object::setpos(int x, int y) {
    dest.x = x;
    dest.y = y;
}
SDL_Rect object::getsrc() {
    return src;
}
SDL_Rect object::getdest() {
    return dest;
}
double object::getscale() {
    return scale;
}