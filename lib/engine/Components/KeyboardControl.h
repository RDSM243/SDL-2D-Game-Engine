#ifndef KEYBOARDCONTROL_COMPONENT_H
#define KEYBOARDCONTROL_COMPONENT_H

#include "engine/Game.h"
#include "engine/EntityManager.h"
#include "engine/Components/Transform2D.h"
#include "engine/Components/Sprite.h"
#include "engine/Components/AnimatedSprite.h"

class KeyboardControl : public Component{
    public:
        KeyboardControl();
        bool IsKeyDown(const char* key);
        bool IsKeyDown(SDL_KeyCode key);
};

#endif