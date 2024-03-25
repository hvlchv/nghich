#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Game{
private:
    SDL_Window* window = nullptr;
    public:

    static SDL_Renderer* renderer;
    static SDL_Event event;
    static int Width;
    static int Height;
    static bool isRunning;

    // Game();
    // ~Game();
    void init();
    void input();
    void update();
    void render();
    void close();

};