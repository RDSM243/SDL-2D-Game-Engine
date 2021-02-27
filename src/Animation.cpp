#include "engine/Components/Animation.h"

Animation::Animation(){
    
}

Animation::Animation(uint32_t index, uint32_t numFrames , uint32_t animationSpeed)
: index(index), numFrames(numFrames), animationSpeed(animationSpeed){}