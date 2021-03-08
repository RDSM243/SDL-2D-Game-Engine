#ifndef TEXTLABEL_COMPONENT_H
#define TEXTLABEL_COMPONENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "engine/EntityManager.h"
#include "engine/AssetManager.h"
#include "engine/FontManager.h"
#include "engine/Game.h"

class TextLabel : public Component{
    public:
        TextLabel(int x, int y, std::string text, std::string fontFamily, const SDL_Color& color);
        void SetLabelText(std::string text, std::string fontFamily);
        virtual void Draw() override;
    private:
        SDL_Rect position;
        std::string text;
        std::string fontFamily;
        SDL_Color color;
        SDL_Texture* texture;

};

#endif