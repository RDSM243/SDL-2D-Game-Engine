#ifndef TRANSFORM_2D_COMPONENT_H
#define TRANSFORM_2D_COMPONENT_H

#include "engine/EntityManager.h"
#include "glm/glm.hpp"

class Transform2D : public Component{
    public:
        Transform2D(glm::vec2 pos = glm::vec2(0.0f, 0.0f), glm::vec2 scl = glm::vec2(1.0f, 1.0f));
        Transform2D(float posX = 0.0f, float posY = 0.0f, float sclX = 1.0f, float sclY = 1.0f);
        glm::vec2 position;
        glm::vec2 scale;
        float rotation;
};

#endif