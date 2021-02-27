#include "engine/Components/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(int width, int height, const char* animationId, int numFrames, int animationSpeed, bool hasDirections) 
: Sprite(width, height, animationId), numFrames(numFrames), animationSpeed(animationSpeed){
    
    if (hasDirections){
        Animation* downAnimation = new Animation(0, numFrames, animationSpeed);
        Animation* rightAnimation = new Animation(1, numFrames, animationSpeed);
        Animation* leftAnimation = new Animation(2, numFrames, animationSpeed);
        Animation* upAnimation = new Animation(3, numFrames, animationSpeed);
        animations.emplace("DownAnimation", downAnimation);
        animations.emplace("RightAnimation", rightAnimation);
        animations.emplace("LeftAnimation", leftAnimation);
        animations.emplace("UpAnimation", upAnimation);
        this->animationindex = 0;
        this->currentAnimationName = "DownAnimation";
    }else{
        Animation* singleAnimation = new Animation(0, numFrames, animationSpeed);
        animations.emplace("SingleAnimation", singleAnimation);
        this->animationindex = 0;
        this->currentAnimationName = "SingleAnimation";
    }

    SetTexture(animationId);
}

void AnimatedSprite::Update(float delta){
    //passa as animações de acordo com os frames e a velocidade da animação
    sourceRectangle.x = sourceRectangle.w * static_cast<int>((SDL_GetTicks() / animationSpeed) % numFrames);
    sourceRectangle.y = animationindex * height;
    destinationRectangle.x = static_cast<int>(transform -> position.x);
    destinationRectangle.y = static_cast<int>(transform -> position.y);
    destinationRectangle.w = width * transform -> scale.x;
    destinationRectangle.h = height * transform -> scale.y;
}

void AnimatedSprite::Play(std::string animationName){
    numFrames = animations[animationName]->numFrames;
    animationindex = animations[animationName]->index;
    animationSpeed = animations[animationName]->animationSpeed;
    currentAnimationName = animationName;
}