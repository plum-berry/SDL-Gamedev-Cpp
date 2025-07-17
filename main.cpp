#include "Game.hpp"

Game* game = nullptr;
int main(int argc, char* argv[]) {


    
    game = new Game();
    game->init("Game",800,800,false);

    while(game->running())
    {
       
        game->handleEvents();
        game->update();
        game->render();

     
    }

game->clean();

    return 0;
}


