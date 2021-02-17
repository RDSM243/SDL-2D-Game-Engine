#include "engine/Components/Transform2D.h"

Transform2D::Transform2D(glm::vec2 pos, glm::vec2 scl) : position(pos), scale(scl), rotation(0.f){}

Transform2D::Transform2D(float posX, float posY, float sclX, float sclY)
: position(glm::vec2(posX, posY)), scale(glm::vec2(sclX, sclY)), rotation(0.f){}
