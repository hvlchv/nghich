
#include "TextureManager.h"
#include "game.h"


SDL_Texture* textureManager::LoadImage(const char* file) {
    SDL_Surface* surface;
    surface = IMG_Load(file);


    SDL_Texture* tex = nullptr;
    tex = SDL_CreateTextureFromSurface(Game::renderer, surface);
    
    SDL_FreeSurface(surface);

    return tex;
}


void textureManager::DrawImage(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer,tex,&src,&dest);
}

void textureManager::DrawImage(SDL_Texture* tex)
{
    SDL_RenderCopy(Game::renderer,tex,NULL,NULL);
}