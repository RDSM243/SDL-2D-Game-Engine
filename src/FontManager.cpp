#include "engine/FontManager.h"

//Add the Font to the FontManager.
TTF_Font* FontManager::LoadFont(const char* fileName, int fontSize){
    return TTF_OpenFont(fileName, fontSize);
}

//Draw the font.
void FontManager::Draw(SDL_Texture* texture, SDL_Rect position){
    SDL_RenderCopy(Game::renderer, texture, NULL, &position);
}