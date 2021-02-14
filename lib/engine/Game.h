#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game{
    public:
        //Game Constructor
        Game();
        //Game Destructor
        ~Game();
        int ticksLastFrame = 0;
        bool IsRunning() const;
        void Init(int width, int height);
        void Input();
        void Update();
        void Draw();
        void Destroy();
    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
};
