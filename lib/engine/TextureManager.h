#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "engine/Game.h"

class TextureManager{
    public:
        static SDL_Texture* LoadTexture(const char* filePath);

        //source Rectangle se trata da posição inicial em que o sprite será desenhado
        //destination Rectangle se trata da posição final onde o sprite será desenhado (no caso o fim da imagem)
        static void Draw(SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect destinationRectangle, SDL_RendererFlip flip);

};

#endif
