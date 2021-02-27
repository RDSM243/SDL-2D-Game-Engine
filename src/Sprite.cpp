#include "engine/Components/Sprite.h"

Sprite::Sprite(int width, int height, const char* filePath) : width(width), height(height){
    SetTexture(filePath);
}

void Sprite::SetTexture(std::string assetTextureId){
    texture = Game::assetManager->GetTexture(assetTextureId);
}

void Sprite::Init(){
    transform = owner -> GetComponent<Transform2D>();
    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    sourceRectangle.w = width;
    sourceRectangle.h = height;
}

void Sprite::Update(float delta){
    destinationRectangle.x = static_cast<int>(transform -> position.x);
    destinationRectangle.y = static_cast<int>(transform -> position.y);
    destinationRectangle.w = width * transform -> scale.x;
    destinationRectangle.h = height * transform -> scale.y;
}

void Sprite::Draw(){
    TextureManager::Draw(texture, sourceRectangle, destinationRectangle, spriteFlip);
}