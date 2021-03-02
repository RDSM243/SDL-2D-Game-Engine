#include "engine/Map.h"


extern EntityManager manager;

Map::Map(const char* textureId, int scale, int tileSize)
: textureId(textureId), scale(scale), tileSize(tileSize){

}

Map::~Map(){}

//Load a .map file on the scene
void Map::LoadMap(const char* filePath, int mapSizeX, int mapSizeY){
    std::fstream mapFile;
    mapFile.open(filePath);

    for(int y = 0; y < mapSizeY; y++){
        for(int x = 0; x < mapSizeX; x++){
                char ch;
                mapFile.get(ch);
                int sourceRectY = atoi(&ch) * tileSize;
                mapFile.get(ch);
                int sourceRectX = atoi(&ch) * tileSize;
                AddTile(sourceRectX, sourceRectY, x * (scale * tileSize), y * (scale * tileSize));
                mapFile.ignore();
        }
    }
    mapFile.close();
}

//Add a tile in a specific position inside a map class
void Map::AddTile(int sourceRectX, int sourceRectY, int x, int y){
    Entity& newTile(manager.AddEntity("Tile", LayerType::TILEMAP_LAYER));
    newTile.AddComponent<Tile>(sourceRectX, sourceRectY, x, y, tileSize, scale, textureId);
}