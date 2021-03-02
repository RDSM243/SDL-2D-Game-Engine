#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "engine/EntityManager.h"
#include "engine/TextureManager.h"
#include "engine/AssetManager.h"

class Tile : public Component{
    public:
        SDL_RendererFlip tileFlip = SDL_FLIP_NONE;
        SDL_Texture* texture; 
        SDL_Rect sourceRectangle;
        SDL_Rect destinationRectangle;
        glm::vec2 position;
        Tile(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, const char* assetTextureId);
        ~Tile();
        virtual void Update(float delta) override;
        virtual void Draw() override;
};

#endif