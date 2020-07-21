//
//  Components.hpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-19.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#ifndef Components_hpp
#define Components_hpp


#include <stdio.h>
#include "ECS.hpp"
class PositionComponet:public Component{
private:
    int xpos,ypos;
public:
    void init()override{
        xpos=0;
        ypos=0;
    }
    int x() {return xpos;}
    int y() {return ypos;}
    void setPos(int x, int y){
        xpos=x;
        ypos=y;
    }
    void update() override{
        xpos++;
        ypos++;
        
    }
    
    
};

#endif /* Components_hpp */
