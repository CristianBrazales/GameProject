//
//  Map.hpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-18.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Game.hpp"
class Map{
public:
    Map();
    ~Map();
    void LoadMap(int[20][25]);
    void DrawMap();
private:
    SDL_Rect src, dst;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    
    int map[20][25];
    
};
#endif /* Map_hpp */
