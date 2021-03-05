#include "engine/Components/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(int width, int height, const char* animationId) 
: Sprite(width, height, animationId){}

void AnimatedSprite::Update(float delta){
    //passa as animações de acordo com os frames e a velocidade da animação
    sourceRectangle.x = sourceRectangle.w * static_cast<int>((SDL_GetTicks() / animationSpeed) % numFrames);
    sourceRectangle.y = animationindex * height;
    Sprite::Update(delta);
}

//Play a animation in the animations list
void AnimatedSprite::Play(std::string animationName){
    numFrames = animations[animationName]->numFrames;
    animationindex = animations[animationName]->index;
    animationSpeed = animations[animationName]->animationSpeed;
    currentAnimationName = animationName;
}

//Add a animation in the animations list
void AnimatedSprite::AddAnimation(const char* animationId, int animationIndex, int numFrames, int animationSpeed){
    animations.emplace(animationId, new Animation(animationIndex, numFrames, animationSpeed));
}