#include"Game.hpp"
Game *game = nullptr;
int main(int argc,char* argv[])
{
  game = new Game();
  game->init("First Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,false);


  while (game->running())
  {
    game->handleEvents();
    game->update();
    game->render();
  }

  game->clean();
  
  return 0;
}