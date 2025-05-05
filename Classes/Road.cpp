#include "Road.h"
#include "Resources.h"

Road::Road(const std::string& type, int capacity, int costMoney, int costMaterials)
    : Buildings(type, capacity, costMoney, costMaterials) {}

void Road::updateBuilding(Resources& resources) {
}

Buildings* Road::clone() const {
    return new Road(*this);
}
