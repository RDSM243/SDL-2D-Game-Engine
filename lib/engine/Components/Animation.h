#ifndef ANIMATION_COMPONENT_H
#define ANIMATION_COMPONENT_H

#include <memory>

class Animation{
    public:
        uint32_t index; 
        uint32_t numFrames; 
        uint32_t animationSpeed;
        Animation();
        Animation(uint32_t index, uint32_t numFrames , uint32_t animationSpeed); 
};

#endif