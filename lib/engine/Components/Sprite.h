#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <SDL2/SDL.h>
#include <memory>
#include "engine/AssetManager.h"
#include "engine/TextureManager.h"
#include "engine/Components/Transform2D.h"

class Sprite : public Component{
    public:
        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
        Sprite(int width, int height, const char* filePath);
        ~Sprite();
        void SetTexture(std::string assetTextureId);
        virtual void Init() override;
        virtual void Update(float delta) override;
        void Draw() override;
        int width, height;
    protected:
        SDL_Texture* texture;
        SDL_Rect sourceRectangle;
        SDL_Rect destinationRectangle;
        Transform2D* transform; 
};

#endif
