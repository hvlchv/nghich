#pragma once
#include <SDL.h>
#include <SDL_image.h>
class Game {
private:
    SDL_Window* window = nullptr;
    public:

    static SDL_Renderer* renderer;
    static SDL_Event event;
    static const int screen_width;
    static const int screen_height;
    static const int game_width;
    static const int game_height;
    static const int grid_width;
    static const int grid_height;
    static bool isRunning;
    static int frame;

    // Game();
    // ~Game();
    void init();
    void input();
    void update();
    void render();
    void close();

};