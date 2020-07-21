//
//  TextureManager.hpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-18.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <stdio.h>
#include "Game.hpp"
class TextureManager{
    public:
    static SDL_Texture* LoadTexture(const char* filename);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
    
};


#endif /* TextureManager_hpp */
