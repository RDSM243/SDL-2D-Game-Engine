#include "engine/EntityManager.h"
#include "engine/Collision.h"
#include "engine/Components/BoxCollider2D.h"

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

    //Draw the entities according to the layer order
    for(int layerNumber = 0; layerNumber < layers_length; layerNumber++){
        for(auto& entity: GetEntitiesByLayer(static_cast<LayerType>(layerNumber))){
            entity -> Draw();
        }
    }
    
    /*
    for(auto& entity: entities){
        entity -> Draw();
    }
    */
}

//Print in the console all the entities on the scene.
void EntityManager::ListAllEntities() const{
    uint32_t i = 0;
    for(auto& entity : entities){
        std::cout << "Entity[" << i << "]" << entity -> name << std::endl;
        entity -> ListAllComponents();
        i++;
    }
}

//Add a entity on the scene in a specific layer.
Entity& EntityManager::AddEntity(std::string entityName, LayerType layer){
    Entity* entity = new Entity(*this, entityName, layer);
    entities.emplace_back(entity);
    return *entity;
}

//Get all the Entites on the scene.
std::vector<Entity*> EntityManager::GetEntities() const{
    return entities;
}

//Get all the entities in a specific layer.
std::vector<Entity*> EntityManager::GetEntitiesByLayer(LayerType layer) const{
    std::vector<Entity*> selectedEntities;
    for(auto& entity: entities){
        if(entity->layer == layer){
            selectedEntities.emplace_back(entity);
        } 
    }
    return selectedEntities;
}

std::string EntityManager::CheckEntityCollisions(Entity* entity) const{
    BoxCollider2D* entityCollider = entity->GetComponent<BoxCollider2D>();
    for(auto& otherEntity: entities){
        if (otherEntity->name.compare(entity->name) != 0 && otherEntity->name.compare("Tile") != 0){
            if(otherEntity->HasComponent<BoxCollider2D>()){
                BoxCollider2D* otherCollider = otherEntity->GetComponent<BoxCollider2D>();
                if(Collision::CheckRectangleCollision(entityCollider->collider, otherCollider->collider)){
                    return otherCollider->colliderTag;
                }
            }
        } 
    }
    return "";
}

//Get the count of entities in the game.
uint32_t EntityManager::GetEntityCount() {
    return entities.size();
}