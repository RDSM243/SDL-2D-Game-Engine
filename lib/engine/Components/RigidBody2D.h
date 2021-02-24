#ifndef RIGIDBODY_2D_COMPONENT_H
#define RIGIDBODY_2D_COMPONENT_H

#include "engine/EntityManager.h"
#include "glm/glm.hpp"
#include "engine/Components/Transform2D.h"

class RigidBody2D : public Component{
    public:
        RigidBody2D(float gravityScaleX=0.f, float gravityScaleY=200.f);
        glm::vec2 velocity;
        virtual void Init() override;
        virtual void Update(float delta) override;
    private:
        Transform2D* transform;
};

#endif