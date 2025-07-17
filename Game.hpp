#ifndef Game_hpp
#define Game_hpp
#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>
#include<iostream>

class Game
{
    private:
        bool is_running;
        SDL_Window *window;
        SDL_Renderer *renderer;
        int count;


    public:
        Game();
        ~Game();

        void init(const char* title,int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running(){return is_running;};

};


#endif