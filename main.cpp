#include <bits/stdc++.h>
#include <SDL.h>

#include "game.h"


int main(int argc, char* argv[]){
    Game* game;
    game = new Game;
    /*game init*/
    game->init();
    /*FPS time*/
    int FPS = 200;
    int BaseTime = 1000 / FPS;
    int FramesTime;
    int FPSstart;
    
    while(Game::isRunning/*game chay*/)
    {
        /*FPS start*/
        FPSstart = SDL_GetTicks();
        game->input();/*game input*/
        game->update();/*game update*/
        game->render();/*game render*/
        FramesTime = SDL_GetTicks() - FPSstart;
        if(FramesTime < BaseTime)
        {
            SDL_Delay(BaseTime - FramesTime);
        }
        /*FPS end*/
    }
    /*game close*/
    return 0;
}