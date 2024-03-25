
#pragma once
#include <SDL.h>

class object {
private:
    SDL_Rect src, dest;
    SDL_Texture* texture;
    double scale = 0.1;
    
public:
    void setlength();
    void init(const char* path);
    void update(int x = 0, int y = 0);
    void render();
    void setsrc(SDL_Rect sr);
    void setdest(SDL_Rect des);
    void setTex(const char* path);
    void setscale(double sca);
    void setpos(int x, int y);
    SDL_Rect getsrc();
    SDL_Rect getdest();
    double getscale();
};