#include "engine/Components/RigidBody2D.h"

RigidBody2D::RigidBody2D(float gravityScaleX, float gravityScaleY) : velocity(glm::vec2(gravityScaleX, gravityScaleY)){}

void RigidBody2D::Init(){
    transform = owner -> GetComponent<Transform2D>();
}

void RigidBody2D::Update(float delta){
    transform -> position.x += velocity.x * delta;
    transform -> position.y += velocity.y * delta;
}