#ifndef KINEMATICBODY_2D_COMPONENT_H
#define KINEMATICBODY_2D_COMPONENT_H

#include "engine/EntityManager.h"
#include "glm/glm.hpp"
#include "engine/Components/Transform2D.h"

class KinematicBody2D : public Component{
    public:
        KinematicBody2D();
        void Move(glm::vec2 velocity);
        virtual void Init() override;
    private:
        Transform2D* transform;
};

#endif