#include "Game.hpp"

SDL_Texture* playerTex;
Game::Game()
{

}

Game::~Game()
{

}
void Game::init(const char* title,int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title,width,height,flags);
    renderer = SDL_CreateRenderer(window,NULL);
    is_running = true;
    SDL_Surface* tmpsurface = IMG_Load("../assets/knight.png");
    if(!tmpsurface)
    {
        SDL_Log("Failed to load image: %s",SDL_GetError());
        is_running = false;
    }
    playerTex = SDL_CreateTextureFromSurface(renderer,tmpsurface);
    SDL_DestroySurface(tmpsurface);

    if(!playerTex)
    {
        SDL_Log("Failed to create texture: %s",SDL_GetError());
        is_running = false;
    }
}


void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_EVENT_QUIT:
        is_running = false;     
        break;
    
    default:
        break;
    }
}

void Game::update()
{
    std::cout<<"Game is running"<<std::endl;
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer,playerTex,NULL,NULL);
    SDL_RenderPresent(renderer);

}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}