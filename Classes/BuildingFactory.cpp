#include "BuildingFactory.h"
#include "Factory.h"
#include "House.h"
#include "Road.h"
#include "PoliceDepartment.h"

Buildings* BuildingFactory::createBuilding(TileType type) {
    switch (type) {
        case TileType::Factory:
            return new Factory("factory", 100, 200, 100, "product", 10, 50, 30);
        case TileType::House:
            return new House("house", 10, 100, 50, 20);
        case TileType::Road:
            return new Road("road", 0, 50, 25);
        case TileType::PoliceDepartment:
            return new PoliceDepartment("policeDepartment", 100, 200, 100);
        default:
            return nullptr;
    }
}

