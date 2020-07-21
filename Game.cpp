//
//  Game.cpp
//  New project
// based on a tutorial: completed by myself
//  Created by Cristian Brazales on 2020-07-18.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "ECS.hpp"
#include "Components.hpp"
GameObject *player;
GameObject *enemy;
SDL_Renderer * Game::renderer=nullptr;
Map* map;
Manager manager;
auto& newPlayer (manager.addEntity());



Game:: Game()
{
    
}
Game::~Game(){
    
}

void Game::init(const char *title, int xpos,int ypos, int width, int height,bool fullscreen)
{
    // check if it is running on full screen:
    int flags=0;
    
    if(fullscreen){
        flags= SDL_WINDOW_FULLSCREEN;
    }
    // check initialization
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){

        std::cout << "sdl intialized"<< std::endl;
        window= SDL_CreateWindow(title,xpos, ypos, width, height, flags);
        if(window)
        {
            std::cout<< "window is created"<< std::endl;
            
        }
        // create a rendered
        renderer= SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"rendered created"<< std::endl;
        }
        isRunning=true;
    }else{
        isRunning=false;
    }
    player = new GameObject("mono.png",0,0);
    enemy= new GameObject("enemy.png",400,0);
    map = new Map();
    newPlayer.addComponent<PositionComponet>();
    newPlayer.addComponent<PositionComponet>().setPos(500, 500);
 
}
void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning=false;
            break;
        default:
            break;
            
    }
    
}
void Game::update(){
    // update all objects from here aim to keep object separate
    player->Update();
    enemy->Update();
    manager.update();
    std::cout<<newPlayer.getComponent<PositionComponet>().x()<<","<<
    newPlayer.getComponent<PositionComponet>().y()<<std::endl;
    
    
}
void Game::render(){
    SDL_RenderClear(renderer);
     map->DrawMap();
    // place to add more renderization
    player->Render();
   
    enemy->Render();
    SDL_RenderPresent(renderer);
    
    
}
void Game::clean(){
    //CLEAN MEMORY AND BUFFERS  
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<< "buffers cleaned"<<std::endl;
    
    
    
}

