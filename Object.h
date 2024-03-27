
#pragma once
#include <SDL.h>

class Object {
private:
    SDL_Rect src, dest;
    SDL_Texture* texture;
    double scale = 1;
    
public:
    void setlength();
    void init(const char* path);
    void move(int x = 0,int y = 0);
  
    void draw();
    void setsrc(SDL_Rect sr);
    void setdest(SDL_Rect des);
    void setwidth(int w);
    void setTex(const char* path);
    void setscale(double sca);
    void setpos(int x, int y);
    SDL_Rect getsrc();
    SDL_Rect getdest();
    double getscale();
    bool collision(SDL_Rect A);
};