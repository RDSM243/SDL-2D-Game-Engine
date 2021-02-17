#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>

class Entity;

class Component{
    public:
        std::unique_ptr<Entity> owner;
        virtual ~Component() {};
        virtual void Init() {};
        virtual void Update(float delta) {};
        virtual void Draw() {};
};

#endif