#include "BuildingFactory.h"
#include "Factory.h"
#include "House.h"
#include "PoliceDepartment.h"
#include "Road.h"

std::unique_ptr<Buildings> BuildingFactory::createBuilding(TileType type) {
  switch (type) {
    case TileType::Factory:
      return std::make_unique<Factory>("factory", 100, 200, 100, "product", 10, 50, 30);
    case TileType::House:
      return std::make_unique<House>("house", 10, 100, 50, 20);
    case TileType::Road:
      return std::make_unique<Road>("road", 0, 50, 25);
    case TileType::PoliceDepartment:
      return std::make_unique<PoliceDepartment>("policeDepartment", 100, 200, 100);
    default:
      return nullptr;
  }
}
