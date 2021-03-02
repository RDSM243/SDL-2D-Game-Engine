#ifndef ANIMATEDSPRITE_COMPONENT_H
#define ANIMATEDSPRITE_COMPONENT_H

#include <SDL2/SDL.h>
#include <memory>
#include "engine/AssetManager.h"
#include "engine/TextureManager.h"
#include "engine/Components/Transform2D.h"
#include "engine/Components/Animation.h"
#include "engine/Components/Sprite.h"

class AnimatedSprite : public Sprite{
    public:
        AnimatedSprite(int width, int height, const char* animationId);
        virtual void Update(float delta) override;
        void Play(std::string animationName);
        void AddAnimation(const char* animationId, int animationIndex, int numFrames, int animationSpeed);
    private:
        int numFrames;
        int animationSpeed;
        std::map<std::string, Animation*> animations;
        std::string currentAnimationName;
        uint32_t animationindex;
};

#endif
