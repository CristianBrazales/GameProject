//
//  GameObject.cpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-18.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"
// the constructor of the game
GameObject::GameObject(const char* texturesheet, int x, int y){
    
    objTexture= TextureManager::LoadTexture(texturesheet);
    xpos=x;
    ypos=y;
}
void GameObject::Update(){

    // update the source
    srcRct.h=32;
    srcRct.w=32;
    srcRct.x=0;
    srcRct.y=0;
    // update the destinatio n
    destRct.x=xpos;
    destRct.y=ypos;
    destRct.w=srcRct.w*2;
    destRct.h=srcRct.h*2;
}
void GameObject::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRct, &destRct);
}

