#include "game.h"
#include "TextureManager.h"
#include "object.h"
#include "player.h"
#include "ball.h"
#include<bits/stdc++.h>

/*static init*/
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game:: event;
bool Game::isRunning = false;
const int Game::screen_width = 800;
const int Game::screen_height = 810;
const int Game::game_width = 540;
const int Game::game_height = 810;
const int Game::grid_width = 30;
const int Game::grid_height = 30;
int Game::frame = 0;
//---------------

SDL_Texture* anh;//background
Player* bkg;
std::vector<Object*> blocks;
Ball* ball;


void Game::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow("hanlong's Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screen_width,screen_height,false);//title, x, y, w, h, flags
        if(window != nullptr)
        {
            renderer = SDL_CreateRenderer(window,-1,0);
            if(renderer != nullptr)
            {
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                isRunning = true;
            }
        }
    }

    ball = new Ball;
    ball->init("img/ball.png");
    ball->setdest({0,0,15,15});
    ball->setpos(270,500);

    bkg = new Player();
    bkg->init("img/player1.png");
    bkg->setpos(400,30*24);

    std::ifstream tileMap("text/map.txt");
    if(tileMap.is_open())std::cout<<"open map\n";
    int type;
    for(int x = 0; x<10; x++)
    {
        for(int y = 0; y<6; y++)
        {
            tileMap>>type;
            if(type > 0)blocks.push_back(new Object);
            switch (type)
            {
            case 1:
                blocks.back()->init("img/1.png");
                break;
            case 2:
                blocks.back()->init("img/2.png");
                break;    
            case 3:
                blocks.back()->init("img/3.png");
                break;
            case 4:
                blocks.back()->init("img/4.png");
                break;
            
            default:
                break;
            }
            if(type > 0)
            {
                blocks.back()->setwidth(90);
                blocks.back()->setpos(y*90,x*30);
            }
        }
    }
    tileMap.close();
    
}

void Game::input()
{
    frame++;
    SDL_PollEvent(&event);

    if(event.type == SDL_QUIT)
    {
        close();
    }

}

void Game::update()
{


    bkg->update();
    ball->update();
    if(bkg->collision(ball->getdest())) ball->update(bkg->getdest());
    for(auto& b : blocks)if(b->collision(ball->getdest()))
    {
        ball->update(b->getdest());
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0,0,255);
    SDL_RenderClear(renderer);
    for (int x = 0; x <= game_width; x += 30) {

            for (int y = 0; y <= game_height; y += 30) {
                // Set color to white
                    const auto rect = SDL_Rect{x,y,grid_width,grid_height};
                    SDL_SetRenderDrawColor(renderer,170,170,170,255);
                    // SDL_RenderDrawRect(renderer,&rect);
                    SDL_RenderDrawPoint(renderer,x,y);
                    
        
                    
                }
                

            }
    SDL_RenderDrawLine(Game::renderer,game_width+1,0,game_width+1,game_height);
         
                    
    
//   textureManager::DrawImage(anh);
    bkg->render();
     for(auto &i : blocks) {
       i->draw();
    }
    ball->render();
    SDL_RenderPresent(renderer);
}
    
void Game::close()
{
    isRunning = false;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}