#ifndef RIGIDBODY_2D_COMPONENT_H
#define RIGIDBODY_2D_COMPONENT_H

#include "engine/EntityManager.h"
#include "glm/glm.hpp"

class RigidBody2D : public Component{
    public:
        RigidBody2D();
        glm::vec2 velocity;
        float gravityScale = 0.f;
};

#endif