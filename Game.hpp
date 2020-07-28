//
//  Game.hpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-18.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
class Game{
    public :
        Game();
        ~Game();
    void init (const char * title, int xpos, int ypos, int width, int height, bool fullscreen);
    void update();
    void render();
    void clean();
    void handleEvents();
    bool running(){ return isRunning;}
    static SDL_Event event;
    static SDL_Renderer * renderer;
private:
    int cnt;
    bool isRunning;
    SDL_Window *window;
 
    
};
#endif /* Game_hpp */
