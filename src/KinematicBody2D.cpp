#include "engine/Components/KinematicBody2D.h"

KinematicBody2D::KinematicBody2D(){}

void KinematicBody2D::Init(){
    transform = owner -> GetComponent<Transform2D>();
}

//Move the Entity according to the velocity values.
void KinematicBody2D::Move(glm::vec2 velocity){
    transform -> position.x += velocity.x;
    transform -> position.y += velocity.y;
}