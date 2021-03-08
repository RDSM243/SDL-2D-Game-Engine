#include "engine/AssetManager.h"

AssetManager::AssetManager(EntityManager* manager) : manager(manager){}

AssetManager::~AssetManager(){}

//Clear the AssetManager.
void AssetManager::ClearData(){
    textures.clear();
    fonts.clear();
}

//Add a texture to the AssetManager.
void AssetManager::AddTexture(std::string textureId, const char* filePath){
    textures.emplace(textureId, TextureManager::LoadTexture(filePath));
}

//Add a font to the AssetManager.
void AssetManager::AddFont(std::string fontId, const char* filePath, int fontSize){
    fonts.emplace(fontId, FontManager::LoadFont(filePath, fontSize));
}

//Return a texture from the AssetManager using the textureId.
SDL_Texture* AssetManager::GetTexture(std::string textureId){
    return textures[textureId];
}

//Return a font from the AssetManager using the fontId.
TTF_Font* AssetManager::GetFont(std::string fontId){
    return fonts[fontId];
}