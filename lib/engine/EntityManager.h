#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "engine/Entity.h"
#include "engine/Component.h"
#include <iostream>

class EntityManager{
    public:
        void ClearData();
        void Update(float delta);
        void Draw();
        void ListAllEntities() const;
        bool HasNoEntities();
        Entity& AddEntity(std::string entityName);
        std::vector<Entity*> GetEntities() const;
        uint32_t GetEntityCount();
    private:
        std::vector<Entity*> entities;
};

#endif
