//
//  SpriteComponent.hpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-27.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include <stdio.h>
#include "Components.hpp"


#include <SDL2/SDL.h>

class SpriteComponent:public Component{
    
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect,destRect;
public:
    SpriteComponent()= default;
    SpriteComponent(const char* path){
        setTex(path);
    }
    void setTex(const char * path){
        texture=TextureManager::LoadTexture(path);
    }
    void init()override{
        transform  =&entity->getComponent<TransformComponent>();
        srcRect.x=srcRect.y=0;
        srcRect.w=srcRect.h=32;
        destRect.w=destRect.h=64;
        
        
        
    }
    void update() override{
        destRect.x=(int)transform->position.x;
        destRect.y=(int)transform->position.y;
        
        
    }
    void draw () override{
        TextureManager::Draw(texture,srcRect,destRect);
        
    }
    
};

#endif /* SpriteComponent_hpp */
