//
//  ECS.hpp
//  New project
//
//  Created by Cristian Brazales on 2020-07-19.
//  Copyright © 2020 Cristian Brazales. All rights reserved.
//

#ifndef ECS_hpp
#define ECS_hpp


#include <stdio.h>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
class Component;
class Entity;
// coponentID is the aloas of size_t an unsigned integer
using ComponentId= std:: size_t;
//inline works like a copy/paste
inline ComponentId getComponentTypeID(){
    
    static ComponentId lastID=0;
    // it will remember the last called
    return lastID ++;

}
// general function with any type
template <typename T> inline ComponentId getComponentTypeID() noexcept{
    static ComponentId typeID=getComponentTypeID();
    return typeID;
}

//constexpr ComponentId maxComponents=32;
constexpr std::size_t maxComponets=32;
using ComponentBitSet= std::bitset<maxComponets>;
using ComponentArray= std::array<Component*, maxComponets>;
// vice class for our components
class Component{
    public :
    Entity* entity;
    virtual void init(){}
    virtual void update(){}
    virtual void draw(){}
    virtual ~Component(){}
    
};
class  Entity{
private:
    bool active=true;
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    
public:
    void update(){
        for(auto& c: components)
            c->update();
        for(auto& c: components)
            c->draw();
    }
    void draw(){
        
    }
    bool isActive(){
        return active;
    }
    void destroy(){
        active=false;
    }
    template <typename T> bool  hasComponent () const
    {
        return componentBitSet[getComponentTypeID<T>];
    }
    template <typename T, typename ... TArgs>
    T& addComponent(TArgs&& ... mArgs){
        T* c(new T(std:: forward<TArgs>( mArgs)...));
        c->entity=this;
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));
        componentArray [getComponentTypeID<T>()]=c;
        componentBitSet[getComponentTypeID<T>()]=true;
        c->init();
        return *c;
    }
    template <typename T> T& getComponent() const
    {
        auto ptr (componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
        
    }
    
};
    class Manager{
    private:
        std:: vector<std::unique_ptr<Entity>> entities;
    public:
        void update(){
            for(auto & e: entities)
                e-> update();
        }
        void draw(){
            for(auto & e: entities)
            e-> draw();
        }
        void refresh(){
            entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                          [](const std:: unique_ptr<Entity> &mEntity)
                                          {
                return !mEntity->isActive();
            }), std::end(entities));
        }
        Entity& addEntity(){
            Entity* e = new Entity();
            std::unique_ptr<Entity> uPtr{e};
            entities.emplace_back(std::move(uPtr));
            return *e;
        }
            
        
    
    
};



#endif /* ECS_hpp */
