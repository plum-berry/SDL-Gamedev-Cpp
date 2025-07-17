#pragma once

#include "Game.hpp"

class GameObject
{
private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_FRect srcRect, destRect;

    SDL_Renderer* renderer;
public:
    GameObject(const char* texturesheet,SDL_Renderer* renderer,int xpos,int ypos);
    ~GameObject();

    void Update();
    void Render();
};
