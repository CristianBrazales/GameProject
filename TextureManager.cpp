//
//  TextureManager.cpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-18.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#include "TextureManager.hpp"
SDL_Texture* TextureManager::LoadTexture(const char *texture)
{
    SDL_Surface* tmpSurface= IMG_Load(texture);
    SDL_Texture* tex= SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    return tex;
}
void::TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

