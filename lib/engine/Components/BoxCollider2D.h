#ifndef BOXCOLLIDER2D_COMPONENT_H
#define BOXCOLLIDER2D_COMPONENT_H

#include "engine/Game.h"
#include "engine/EntityManager.h"
#include "engine/Components/Sprite.h"
#include "engine/Components/AnimatedSprite.h"

class BoxCollider2D : public Component{
    public:
        BoxCollider2D(std::string colliderTag, int x, int y, int width, int height);
        virtual void Init() override;
        virtual void Update(float delta) override;
        virtual void Draw() override;
        bool CheckCollisionWith(std::string entityName);
        std::string colliderTag;
        SDL_Rect collider;
        SDL_Rect sourceRec;
        SDL_Rect destinationRec;
        bool isSolid = false;
    private:
        Transform2D* transform;
};

#endif