//Se CONSTANTS_H não estiver difinido defina CONSTANTS_H
#ifndef CONSTANTS_H
#define CONSTANTS_H

const uint32_t WINDOW_WIDTH = 800;
const uint32_t WINDOW_HEIGHT = 600;

//Frames per second
const uint32_t FPS = 60;

//In miliseconds
const uint32_t FRAME_TARGET_TIME = 1000 / FPS;

enum class LayerType {
    TILEMAP_LAYER,
    VEGETATION_LAYER,
    ENEMY_LAYER,
    PLAYER_LAYER,
    PROJECTILE_LAYER,
    UI_LAYER,
    LENGTH
};

const int layers_length = static_cast<int>(LayerType::LENGTH);

#endif