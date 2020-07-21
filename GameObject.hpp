//
//  GameObject.hpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-18.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Game.hpp"

class GameObject{
public:
    GameObject(const char* texturesheet, int x, int y);
    ~GameObject();
    void Update();
    void Render();
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objTexture;
    SDL_Rect srcRct, destRct;
    
    
};

#endif /* GameObject_hpp */
