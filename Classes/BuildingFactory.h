#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Buildings.h"
#include "TileType.h"
#include <memory>
class BuildingFactory {
public:
  static std::unique_ptr<Buildings> createBuilding(TileType type);
};

#endif // BUILDINGFACTORY_H
