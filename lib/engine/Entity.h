#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <memory>
#include <string>
#include <map>

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
            
            //passando o componente para uma lista de componentes
            componentTypeMap[&typeid(*newComponent)] = newComponent;
            
            newComponent->Init();

            return *newComponent;
        }

        template<typename T>
        T* GetComponent(){
            return static_cast<T*>(componentTypeMap[&typeid(T)]);
        }

    private:
        EntityManager& manager;
        bool isActive;
        std::vector<Component*> components;
        std::map<const std::type_info*, Component*> componentTypeMap;
};

#endif