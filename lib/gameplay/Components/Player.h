#ifndef PLAYER_COMPONENT_H
#define PLAYER_COMPONENT_H

#include "engine/EntityManager.h"
#include "engine/Components/Transform2D.h"
#include "engine/Components/AnimatedSprite.h"
#include "engine/Components/KeyboardControl.h"
#include "engine/Components/KinematicBody2D.h"
#include "engine/Components/Camera2D.h"

class Player : public Component{
    public:
        Player();
        virtual void Init() override;
        virtual void Update(float delta) override;
    private:
        Transform2D* transform;
        AnimatedSprite* animatedSprite;
        KeyboardControl* keyboardControl;
        KinematicBody2D* kinematicBody2D;
        Camera2D* camera2D;
        glm::vec2 velocity;
        const int moveSpeed = 100;
};

#endif