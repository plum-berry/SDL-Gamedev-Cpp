#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject* player;
GameObject* enemy;
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
    player = new GameObject("../assets/knight.png",renderer,0,0);
    enemy = new GameObject("../assets/knight.png",renderer,50,50);
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
player->Update();
enemy->Update();
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderClear(renderer);
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);

}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}