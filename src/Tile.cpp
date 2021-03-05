#include "engine/Components/Tile.h"

Tile::Tile(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, const char* assetTextureId){
    texture = Game::assetManager -> GetTexture(assetTextureId);
    sourceRectangle.x = sourceRectX;
    sourceRectangle.y = sourceRectY;
    sourceRectangle.w = tileSize;
    sourceRectangle.h = tileSize;

    destinationRectangle.x = x;
    destinationRectangle.y = y;
    destinationRectangle.w = tileSize * tileScale;
    destinationRectangle.h = tileSize * tileScale;

    position.x = x;
    position.y = y;
}

Tile::~Tile(){
    SDL_DestroyTexture(texture);
}

void Tile::Update(float delta){
    //Updating tile position according to the camera position
    destinationRectangle.x = position.x - Game::cameraRect.x;
    destinationRectangle.y = position.y - Game::cameraRect.y;
}

void Tile::Draw(){
    TextureManager::Draw(texture, sourceRectangle, destinationRectangle, tileFlip);
}
