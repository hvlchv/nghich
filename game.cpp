#include "game.h"
#include "TextureManager.h"
#include "Object.h"

/*static init*/
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game:: event;
bool Game::isRunning = false;

//---------------

SDL_Texture* anh;//background
object* flo;


void Game:: init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow("hanlong's Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,400,false);//title, x, y, w, h, flags
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

    anh = textureManager::LoadImage("img/1.png");
    //flo->setImage("img/1.png");
    flo->init("img/flo.png");
    
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
    //if(flo->getXpos() > 100)flo->setScale(2);
   // flo->setPos(flo->getXpos()+10, flo->getYpos());
   // flo->update();
}

void Game::render()
{
   // SDL_RenderClear(renderer);

   // textureManager::DrawImage(anh);
   // flo->render();

    SDL_RenderPresent(renderer);
}

void Game::close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}