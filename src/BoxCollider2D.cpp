#include "engine/Components/BoxCollider2D.h"

int sprite_width, sprite_height;

BoxCollider2D::BoxCollider2D(std::string colliderTag, int x, int y, int width, int height)
: colliderTag(colliderTag), collider({x, y, width, height}){}

void BoxCollider2D::Init(){
    transform = owner -> GetComponent<Transform2D>();

    //verificando se a classe é animated ou sprite
    if (owner -> HasComponent<Sprite>()){
        sprite_width = owner -> GetComponent<Sprite>()->width;
        sprite_height  = owner -> GetComponent<Sprite>()->height;
    }else{
        sprite_width = owner -> GetComponent<AnimatedSprite>()->width;
        sprite_height  = owner -> GetComponent<AnimatedSprite>()->height;
    }

    sourceRec = {0, 0, sprite_width, sprite_height};
    destinationRec = {collider.x, collider.y, collider.w, collider.h};
}

void BoxCollider2D::Update(float delta){
    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);
    collider.w = sprite_width * transform->scale.x;
    collider.h = sprite_height * transform->scale.y;
    destinationRec.x = collider.x - Game::cameraRect.x;
    destinationRec.y = collider.y - Game::cameraRect.y;
}

void BoxCollider2D::Draw(){
    SDL_Rect colliderBox {
        (int) destinationRec.x,
        (int) destinationRec.y,
        sprite_width,
        sprite_height
    };

    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(Game::renderer, &colliderBox);
}

//Check the collision with another entity and returning true in case the collision happens.
bool BoxCollider2D::CheckCollisionWith(std::string entityName){
    std::string collisionTagType = Game::GetEntityManager()->CheckEntityCollisions(owner);
    if (collisionTagType.compare(entityName) == 0){
        return true;
    }
    return false;
}