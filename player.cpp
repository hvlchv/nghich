#include "player.h"
#include "game.h"

void Player::input() {
    
    if(Game::event.type == SDL_KEYDOWN)
    {
        switch(Game::event.key.keysym.sym )
        {
            case SDLK_a:
            vx = -5;
            break;
            case SDLK_d:
            vx = 5;
            break;
        }
    }
    if(Game::event.type == SDL_KEYUP)
    {
        switch(Game::event.key.keysym.sym )
        {
            case SDLK_a:
            vx = 0;
            break;
            case SDLK_d:
            vx = 0;
            break;
        }
    }
    update(vx,vy);
}