#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include "engine/Entity.h"
#include "engine/Component.h"
#include "engine/EntityManager.h"

class AssetManager;

class Game{
    public:
        //Game Constructor
        Game();
        //Game Destructor
        ~Game();
        int ticksLastFrame = 0;
        bool IsRunning() const;
        static SDL_Renderer *renderer;
        static AssetManager* assetManager;
        static SDL_Event event;
        void LoadLevel(int levelNumber);
        void Init(int width, int height);
        void Input();
        void Update();
        void Draw();
        void Destroy();
    private:
        bool isRunning;
        SDL_Window *window;
};

#endif