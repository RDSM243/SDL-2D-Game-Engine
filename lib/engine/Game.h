#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game{
    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
    public:
        //Game Constructor
        Game();
        //Game Destructor
        ~Game();
        bool IsRunning() const;
        void Init(int width, int height);
        void Input();
        void Update();
        void Draw();
        void Destroy();
};
