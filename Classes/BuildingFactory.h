#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Buildings.h"
#include "TileType.h"

class BuildingFactory {
public:
    static Buildings* createBuilding(TileType type);
};



#endif //BUILDINGFACTORY_H
