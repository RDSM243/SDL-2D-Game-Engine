#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>
#include <string>
#include "engine/TextureManager.h"
#include "engine/EntityManager.h"

class AssetManager{

    public:
        AssetManager(EntityManager* manager);
        ~AssetManager();
        void ClearData();
        void AddTexture(std::string textureId, const char* filePath);
        SDL_Texture* GetTexture(std::string textureId);
    private:
        EntityManager* manager;
        std::map<std::string, SDL_Texture*> textures;
};

#endif