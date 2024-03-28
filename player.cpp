#include "player.h"
#include "game.h"

void Player::update() {
    
    if(Game::event.type == SDL_KEYDOWN)
    {
        switch(Game::event.key.keysym.sym )
        {
            case SDLK_a:
            {
                Left = 1;
                Right = 0;
            }
            break;
            case SDLK_d:
            {
                Left = 0;
                Right = 1;
            }
            break;
        }
    }
    if(Game::event.type == SDL_KEYUP)
    {
        switch(Game::event.key.keysym.sym )
        {
            case SDLK_a:
            Left = 0;
            break;
            case SDLK_d:
            Right = 0;
            break;
        }
    }
    if (Left)vx = -6;
    else if (Right)vx = 6;
    else vx = 0;
    move(vx,vy);
}

void Player::render()
{
    draw();
}