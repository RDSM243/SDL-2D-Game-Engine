#include "engine/Components/TextLabel.h"

TextLabel::TextLabel(int x, int y, std::string text, std::string fontFamily, const SDL_Color& color){
    this->position.x = x;
    this->position.y = y;
    this->text = text;
    this->fontFamily = fontFamily;
    this->color = color;
    SetLabelText(text, fontFamily);
}

void TextLabel::SetLabelText(std::string text, std::string fontFamily){
    SDL_Surface* surface = TTF_RenderText_Blended(Game::assetManager->GetFont(fontFamily), text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
}

void TextLabel::Draw(){
    FontManager::Draw(texture, position);
}

