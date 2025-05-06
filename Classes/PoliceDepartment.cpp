#include "PoliceDepartment.h"
#include "House.h"
#include <vector>
PoliceDepartment::PoliceDepartment(const std::string& type, int capacity, int costMoney, int costMaterials)
    : Buildings(type, capacity, costMoney, costMaterials) {}

std::vector<House*> PoliceDepartment::findNearbyHouses() {
    std::vector<House*> nearbyHouses;
    if (!cityBuildings) return nearbyHouses;

    for (Buildings* building : *cityBuildings) {
        if (House* house = dynamic_cast<House*>(building)) {
            nearbyHouses.push_back(house);
        }
    }
    return nearbyHouses;
}

void PoliceDepartment::updateBuilding([[maybe_unused]] Resources& resources) {
    for (House* house : findNearbyHouses()) {
        float currentSatisfaction = house->getSatisfaction();
        house->setSatisfaction(currentSatisfaction + satisfactionIncrease);
    }
}


Buildings* PoliceDepartment::clone() const {
    return new PoliceDepartment(*this);
}