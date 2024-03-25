#pragma once
#include "include/SDL.h"
#include "include/SDL_image.h"

class textureManager {
public: 
    static SDL_Texture* LoadImage(const char* file);
    static SDL_Texture* LoadImage(const char* file, SDL_Rect &src);



    static void DrawImage(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
    static void DrawImage(SDL_Texture* tex);

};