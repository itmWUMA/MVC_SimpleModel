#include "Map.h"

Map* Map::MapInstance = new Map;

Map* Map::Get()
{
    return MapInstance;
}
