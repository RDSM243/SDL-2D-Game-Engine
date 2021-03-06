#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>

#include "engine/EntityManager.h"
#include "engine/Component.h"
#include "engine/Constants.h"

class EntityManager;
class Component;

class Entity{
    public:
        std::string name;
        LayerType layer;
        Entity(EntityManager& manager);
        Entity(EntityManager& manager, std::string name, LayerType layer);
        void Update(float delta);
        void Draw();
        void Destroy();
        void ListAllComponents() const;
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

        //Template to verify if the function has a specific component.
        template<typename T>
        bool HasComponent() const{
            return componentTypeMap.count(&typeid(T));
        }

        //Get a specific component from the Entity.
        template<typename T>
        T* GetComponent(){
            //Verifying if the requested component exists
            if (HasComponent<T>()){
                return static_cast<T*>(componentTypeMap[&typeid(T)]);
            }
            std::cerr << "Can't find a component in the entity " << name << std::endl;
            return NULL;
        }

    private:
        EntityManager& manager;
        bool isActive;
        std::vector<Component*> components;
        std::map<const std::type_info*, Component*> componentTypeMap;
};

#endif