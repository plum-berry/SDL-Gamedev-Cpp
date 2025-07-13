#include "Game.hpp"

Game::Game()
{

}

Game::~Game()
{

}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{   

    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
        if(SDL_Init(SDL_INIT_EVERYTHING)==0)
        {
            std::cout<<"Subsystems Initialized!.."<<std::endl;
        

        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);

        if(window)
        {
            std::cout<<"Window Created"<<std::endl;
        }

        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer)
        {   
            SDL_SetRenderDrawColor(renderer,0,255,0,255);
            std::cout<<"Rendere Created"<<std::endl;
        }

        is_running = true;
    }
    else
    {
        is_running = false;
    }
    
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        is_running = false;
        break;
    
    default:
        break;
    }
}

void Game::update()
{
    count++;
    std::cout<<count<<std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);



    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game Closed"<<std::endl;
}

bool Game::running()
{
    return is_running;
}