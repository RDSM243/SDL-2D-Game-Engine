#include "engine/EntityManager.h"

void EntityManager::ClearData(){
    for(auto& entity: entities){
        entity->Destroy();
    }
}

bool EntityManager::HasNoEntities(){
    return entities.size() == 0;
}

void EntityManager::Update(float delta){
    for(auto& entity: entities){
        entity -> Update(delta);
    }
}

void EntityManager::Draw(){
    for(auto& entity: entities){
        entity -> Draw();
    }
}

Entity& EntityManager::AddEntity(std::string entityName){
    Entity* entity = new Entity(*this, entityName);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() const{
    return entities;
}

uint32_t EntityManager::GetEntityCount() {
    return entities.size();
}