#include "game.h"
#include "TextureManager.h"
#include "Object.h"
#include "player.h"
/*static init*/
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game:: event;
bool Game::isRunning = false;
int Game::Width = 1200;
int Game::Height = 800;

//---------------

SDL_Texture* anh;//background
Player* flo;


void Game:: init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow("hanlong's Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Width,Height,false);//title, x, y, w, h, flags
        if(window != nullptr)
        {
            renderer = SDL_CreateRenderer(window,-1,0);
            if(renderer != nullptr)
            {
                SDL_SetRenderDrawColor(renderer,100,100,100,255);
                isRunning = true;
            }
        }
    }

    flo = new Player();
   // anh = textureManager::LoadImage("img/1.png");
    
    flo->init("img/block.png");
    flo->setpos(400,700);
    flo->setscale(1.32);
    
}

void Game:: input()
{
    SDL_PollEvent(&event);

    if(event.type == SDL_QUIT)
    {
        close();
    }

}

void Game:: update()
{
    // if(flo->getdest().x> 100)flo->setscale(0.2);
    // else flo->setscale(0.1);
    //flo->setpos(flo->getdest().x+1, flo->getdest().y);

    flo->input();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
//   textureManager::DrawImage(anh);
    flo->render();

    SDL_RenderPresent(renderer);
}

void Game::close()
{
    isRunning = false;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}