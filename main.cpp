//
//  Game tutorial follow
// Objective: create a simple game using C++ and SDL library for graphics
//
//  Created by Cristian Brazales on 2020-07-17.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//


#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.hpp"
Game *game=nullptr;
const int width=600;
const int height=640;
const int FPS=60;
const int framedelay=1000/FPS;
Uint32 frameStart;
int frameTime;


int main( int argc, char *argv[] )
{
    frameStart=SDL_GetTicks();
    // CREATE THE GAME OBJ
    game= new Game();
    game->init("tutorial game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  width, height, false);
    while(game->running()){
        game->handleEvents();
        game->update();
        game->render();
        frameTime=SDL_GetTicks()-frameStart;
        if(framedelay>frameTime)
            SDL_Delay(framedelay-frameTime);
    }
    game->clean();
    
    
    return EXIT_SUCCESS;
}
