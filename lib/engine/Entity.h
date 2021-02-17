#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <memory>
#include <string>

#include "engine/EntityManager.h"
#include "engine/Component.h"

class EntityManager;
class Component;

class Entity{
    public:
        std::string name;
        Entity(EntityManager& manager);
        Entity(EntityManager& manager, std::string name);
        void Update(float delta);
        void Draw();
        void Destroy();
        bool GetActiveState() const;

        //função para adicionar qualquer tipo de componente
        template<typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args){
            T* newComponent(new T(std::forward<TArgs>(args)...));

            newComponent->owner = this;
            components.emplace_back(newComponent);
            newComponent->Init();

            return *newComponent;
        }

    private:
        EntityManager& manager;
        bool isActive;
        std::vector<std::unique_ptr<Component>> components;
};

#endif