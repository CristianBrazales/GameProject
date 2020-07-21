//
//  Map.cpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-18.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#include "Map.hpp"
#include "TextureManager.hpp"
// mapping of screen to texture
int maplvl1[20][25] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
};

Map::Map(){
    dirt= TextureManager::LoadTexture("dirt.png");
    grass= TextureManager::LoadTexture("grass.png");
    water= TextureManager::LoadTexture("water.png");
    if(!water || !grass || !dirt)
        std::cout<< "error no textures loaded"<<std::endl;
    LoadMap(maplvl1);
    src.x=src.y=0;
    src.w=dst.w=32;
    src.h=dst.h=32;
    dst.x=0;
    dst.y=0;
    
}
void Map::LoadMap(int arr[20][25]){
    for(int row=0;row< 20;row++){
        for(int col=0; col<25; col++){
            map[row][col]=arr[row][col];
        }
    }
    
}
    
void Map::DrawMap()
{int type=0;
    for(int row=0;row< 20;row++){
        for(int col=0; col<25; col++){
            type= map[row][col];
            // do the maping of the rectangules to map to the screen
            // each one should go 32 spaces next to the other
            dst.x=col*32;
            dst.y=row*32;
            
            switch (type) {
                case 0:
                    TextureManager::Draw(water, src, dst);
                    break;
                case 1:
                    TextureManager::Draw(grass, src, dst);
                    break;
                case 2:
                    TextureManager::Draw(dirt, src, dst);
                    break;
                        
                default:
                    TextureManager::Draw(water, src, dst);
                                       break;
            }
        }
    }
        
}

