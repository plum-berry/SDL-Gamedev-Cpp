#include "GameObject.hpp"
#include "TextureManager.hpp"
GameObject::GameObject(const char* texturesheet,SDL_Renderer* renderer,int xpos, int ypos)
{
    this->renderer = renderer;

    objTexture = TextureManager::LoadTexture(texturesheet,renderer);
    SDL_SetTextureScaleMode(objTexture,SDL_SCALEMODE_NEAREST);

    this->xpos = xpos;
    this->ypos = ypos;
}

void GameObject::Update()
{
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = 64;
    destRect.w = 64;

    destRect.x = xpos;
    destRect.y = ypos;

}

void GameObject::Render()
{
    SDL_RenderTexture(renderer,objTexture,&srcRect,&destRect);
}