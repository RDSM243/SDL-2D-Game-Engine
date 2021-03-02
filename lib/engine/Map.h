#ifndef MAP_H
#define MAP_H

#include "engine/EntityManager.h"
#include "engine/Components/Tile.h"
#include <fstream>
#include "engine/Game.h"

class Map{
    public:
        Map(const char* textureId, int scale, int tileSize);
        ~Map();
        void LoadMap(const char* filePath, int mapSizeX, int mapSizeY);
        void AddTile(int sourceX, int sourceY, int x, int y);
    private:
        const char* textureId;
        int scale;
        int tileSize;
};

#endif