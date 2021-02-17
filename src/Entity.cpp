#include "engine/Entity.h"

Entity::Entity(EntityManager& manager): manager(manager){
    this->isActive = true;
}

Entity::Entity(EntityManager& manager, std::string name): manager(manager), name(name){
    this->isActive = true;
}

void Entity::Update(float delta){
    for(auto& component: components) {
        component->Update(delta);
    }
}

void Entity::Draw(){
    for(auto& component: components) {
        component->Draw();
    }
}

void Entity::Destroy(){
    this->isActive = false;
}

bool Entity::GetActiveState() const{
    return this->isActive;
}